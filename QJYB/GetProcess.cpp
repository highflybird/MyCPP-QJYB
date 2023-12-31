#include "stdafx.h"
#include <TlHelp32.h>
#include <Psapi.h>
#include "GetProcess.h"
#include "GetFunctionAddress.h"

#pragma comment(lib, "version.lib")
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "mscoree.lib")

struct LANGANDCODEPAGE 
{
	WORD wLanguage;
	WORD wCodePage;
} *lpTranslate;

//存储映射关系的数据结构DosMapToDeviceName
//第一个wstring是DoS盘符名，如C:
//第二个是Volume中路径,如/Device/HarddiskVolume1
typedef std::map<std::wstring, std::wstring> DosMapToDeviceName; 

//定义一个数组，A到Z有26个字母
DosMapToDeviceName mapName;

//----------------------------------------------------------------------------------
//枚举回调函数
BOOL CALLBACK EnumWindowsProc(HWND hWnd,LPARAM lParam)
{
	DWORD dwProcessId;
	LPWNDINFO pInfo = (LPWNDINFO)lParam;
	//通过窗口句柄获取进程ID
	int ret = ::GetWindowThreadProcessId(hWnd, &dwProcessId);
	if(dwProcessId == pInfo->dwProcessId &&  IsWindowVisible(hWnd)) 
	{
		TCHAR szClassName[BUFSIZ];
		ret = ::GetClassName(hWnd,szClassName,BUFSIZ); 
		HWND hParent = (HWND)::GetWindowLong(hWnd,-8);   //GWL_HWNDPARENT ;_WIN64,  GWLP_HWNDPARENT
		TCHAR szText[MAX_PATH];
		ret = ::GetWindowText(hWnd,szText,MAX_PATH);
		if (hParent == 0 && _tcsncmp(szClassName,_T("Afx"),3) == 0 && ret != 0)
		{
			//匹配遍历窗口进程号与通过进程名得到的进程号
			TRACE( _T("EnumWindowsProc..hWnd=0x%x, ProcessID=%d, WindowsText=%s \n"), hWnd, dwProcessId, szText );
			pInfo->hWnd = hWnd;
			pInfo->strClassName = szClassName;
			pInfo->strWindowText = szText;
			return FALSE;
		}
	}
	return TRUE;
}

//----------------------------------------------------------------------------------
//根据进程号获取模块列表
void GetModuleByProcessID(DWORD processId,WNDINFO & wi)
{
	HMODULE hHandle = NULL;
	HMODULE hMods[1024];
	HANDLE hProcess;
	DWORD cbNeeded;
	//hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION | PROCESS_VM_WRITE, FALSE, processId);
	hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE,FALSE, processId);
#ifdef _WIN64
	int ret = EnumProcessModulesEx(hProcess,hMods,sizeof(hMods),&cbNeeded,LIST_MODULES_ALL);
#else
	int ret = EnumProcessModules(hProcess,hMods,sizeof(hMods),&cbNeeded);
#endif
	if (hProcess && ret)
	{
		//判断是否为Wow64程序
		BOOL isWOW64;
		SYSTEM_INFO si;
		IsWow64Process(hProcess,&isWOW64);
		GetNativeSystemInfo(&si);
		if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 || si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64 )
			wi.is64bit = !isWOW64;
		else
			wi.is64bit = false;
  

		//列出进程中所有模块
		for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); i++ )
		{
			TCHAR szModName[MAX_PATH];
			// Get the full path to the module's file.
			if ( GetModuleFileNameEx( hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				CString szTemp = szModName;
				szTemp = szTemp.Right(8);
				if (szTemp.CompareNoCase(_T("acad.exe"))==0)
				{
					wi.hMod = hMods[i];
					continue;
				}

				szTemp = szModName;
				CString szTemp1;
				szTemp = szTemp.Right(10);
				szTemp1.Format(_T("%s%s"),szTemp.Left(4),szTemp.Right(4));
				if (szTemp1.CompareNoCase(_T("acdb.dll"))==0)
				{
					wi.hAcDb = hMods[i];
					wi.strAcDbPath = szModName;
					continue;
				}
	
				szTemp = szModName;
				szTemp = szTemp.Right(10);
				if (szTemp.CompareNoCase(_T("accore.dll"))==0)
				{
					wi.hAcCore = hMods[i];
					wi.strAcCorePath = szModName;
				}
			}
		}
		CloseHandle( hProcess );
	}
	else
	{
		ret = GetLastError();
	}
}

//获取所有的CAD的进程号，窗口句柄，类名，窗口标题，
int FindProcessByName(LPCTSTR szNameOfImage,MapProcessIDToWndinfo & WndSet)
{
	CString strProcess(szNameOfImage);
	//匹配进程名是否含 exe
	if (_tcscmp(strProcess.Right(strProcess.GetLength() - strProcess.ReverseFind('.') - 1),_T("exe")))
	{	
		return -1;//参数错误返回-1
	}
	//************************根据进程名称获取进程ID***********//
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot)
	{
		return 0;
	}

	SetMapping(); 
	//WndSet.clear();
	//因为用了map,所以不能清空。
	vector<DWORD> ProcessIdList;//存放进程PID的数组

	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL fOk = Process32First(hSnapshot, &pe); fOk; fOk = Process32Next(hSnapshot, &pe))
	{
		TRACE(_T("当前查找进程的名称是: %s\n"),pe.szExeFile);
		TRACE(_T("当前进程PID： %d \n"),pe.th32ProcessID);
		if (!_tcscmp(pe.szExeFile, szNameOfImage))
		{
			TRACE(_T("当前匹配的进程PID： %d \n"),pe.th32ProcessID);
			ProcessIdList.push_back(pe.th32ProcessID);
		}
	}
	//进程数量为0 提示找不到进程 返回为0；
	if (ProcessIdList.size() == 0)
	{
		WndSet.clear();
		return 0;
	}

	//对一些已经关闭的进程删除
	MapProcessIDToWndinfo::iterator itrWndSet = WndSet.begin();
	vector<DWORD>::iterator itrProcessId;
	for (;itrWndSet != WndSet.end();)
	{
		itrProcessId = find(ProcessIdList.begin(),ProcessIdList.end(), itrWndSet->first);
		if (itrProcessId == ProcessIdList.end())
		{
			WndSet.erase(itrWndSet++);
			continue;
		}
		itrWndSet++;
	}

	//对一个进程名有多个相同进程ID的全部数组进行处理
	for (DWORD j=0;j<ProcessIdList.size();j++)
	{
		itrWndSet = WndSet.find(ProcessIdList[j]);
		if (itrWndSet == WndSet.end())
		{
			WNDINFO wi;
			wi.hWnd = NULL; 
			wi.dwProcessId = ProcessIdList[j];//将获取到的进程ID传给结构体
			wi.strAppPath = GetProcessFullName(ProcessIdList[j]);
			wi.strVersion = GetAppVersion(wi.strAppPath);
			GetModuleByProcessID(ProcessIdList[j],wi);
			//遍历顶层窗口获取窗口句柄
			EnumWindows(EnumWindowsProc,(LPARAM)&wi);
			//判断当前进程是否无窗口 无窗口句柄则不保存
			if(wi.hWnd != NULL)
			{
				WndSet[ProcessIdList[j]] = wi;
			}
		}
	}
	return WndSet.size();//返回句柄个数
}

//获取文件版本号
CString GetAppVersion(LPCTSTR pcszFileName)
{
	DWORD dwSize = 0;
	DWORD uiSize = GetFileVersionInfoSize(pcszFileName,&dwSize);
	if (0 == uiSize)
	{
		//0 意味着GetFileVersionInfoSize 函数调用失败
		return _T("");
	}

	PTSTR pBuffer = new TCHAR[uiSize];

	if (NULL == pBuffer)
	{
		//分配内存失败:)
		return _T("");
	}

	memset((void*)pBuffer,0,uiSize);

	//获取exe 或 DLL 的资源信息，存放在pBuffer内
	if(!GetFileVersionInfo(pcszFileName,0,uiSize,(PVOID)pBuffer))
	{
		//GetFileVersionInfo 调用失败.
		delete []pBuffer;
		return _T("");
	}


	LANGANDCODEPAGE *pLanguage = NULL;  //这里这样设置没关系了。

	UINT  uiOtherSize = 0;
	//获取资源相关的 codepage 和language 
	if (!VerQueryValue(pBuffer,_T("\\VarFileInfo\\Translation"),
		(PVOID*)&pLanguage,&uiOtherSize))
	{
		//出错
		delete []pBuffer;
		return _T("");
	}

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//超级重点:
	//一定要把pTmp这个变量设置成PVOID或LPVOID型的 否则无法获取信息。
	LPVOID pTmp = NULL;   
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	CString SubBlock;
	CString strVersion;

	for(UINT i=0; i < (uiOtherSize / sizeof(LANGANDCODEPAGE)); i++ )
	{
		//获取每种 CodePage 和 Language 资源的相关信息
		SubBlock.Format(_T("\\StringFileInfo\\%04x%04x\\FileVersion"),pLanguage[i].wLanguage,pLanguage[i].wCodePage);
		//   Comments InternalName ProductName 
		//   CompanyName LegalCopyright ProductVersion 
		//   FileDescription LegalTrademarks PrivateBuild 
		//   FileVersion OriginalFilename SpecialBuild  
		//	 OriginalFilename 可由上面的各种代替。
		//   Retrieve file description for language and code page "i". 

		int nRet = VerQueryValue(pBuffer, SubBlock.GetBuffer(), (LPVOID*)&pTmp, &uiOtherSize); 
		if (nRet != 0)
		{
			strVersion.Format(_T("%s"),(TCHAR*)pTmp);
		}
	}
	delete []pBuffer;
	pBuffer = NULL;
	return strVersion;
}

//找到所有的盘符，枚举找到对应的路径，并存储到mapName
void SetMapping()
{
	WCHAR lpDeviceName[3] = L"C:";
	WCHAR lpTargetPath[MAX_PATH];
	DWORD ns;
	for( WCHAR c = L'A'; c <= L'Z'; c++)
	{
		lpDeviceName[0] = c;
		ns = QueryDosDeviceW(lpDeviceName,lpTargetPath,MAX_PATH);
		if (ns)
		{
			mapName[lpDeviceName] = lpTargetPath;
		}
	}
}

//对于设备路径path，与mapName对比，将VolumeDevice名字换成对应的盘符名字
void doPathMapping(WCHAR* path)
{
	int len = wcslen(path);
	int result = 0;
	int j,k;
	DosMapToDeviceName::iterator itr = mapName.begin();
	wstring strTemp;
	for(;itr!=mapName.end();itr++)
	{
		int l = itr->second.length();
		const WCHAR* lpPathName = itr->first.c_str();
		strTemp = itr->second;
		strTemp.append(L"\\");
		result = wmemcmp(strTemp.c_str(),path,l+1);
		if (result == 0)
		{
			for(j=2,k = l;k<len;j++,k++)
				path[j] = path[k];
			for(;j<len;j++)
				path[j]=L'\0';
			path[0] = lpPathName[0];
			path[1] = lpPathName[1];
			break;
		}
	}
}

//获取进程路径
CString GetProcessFullName( DWORD idProcess )
{
	// 获取进程路径
	TCHAR szProcessName[MAX_PATH] = _T("");
	// 打开进程句柄,需要管理员权限
	HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, idProcess );
	if( NULL != hProcess )
	{
		//三种获取路径的办法
		DWORD ret = GetProcessImageFileName(hProcess,szProcessName,MAX_PATH);
		doPathMapping(szProcessName);
		CloseHandle( hProcess );
	}
	return (szProcessName);
}

// 显示错误信息  
DWORD GetLastErrorBox(HWND hWnd, LPCTSTR lpTitle, CString & messageOut)  
{  
	LPVOID lpv;  
	DWORD dwRv;  

	if (GetLastError() == 0)
		return 0;  

	dwRv = FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |  FORMAT_MESSAGE_FROM_SYSTEM,  
		NULL,  
		GetLastError(),  
		GetUserDefaultUILanguage(),
		//MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),  
		(LPTSTR)&lpv,  
		0,  
		NULL);  
    messageOut = (LPTSTR)lpv;
	//MessageBox(hWnd, (LPTSTR)lpv, lpTitle, MB_OK);  

	if(dwRv)  
		LocalFree(lpv);  

	SetLastError(0);  
	return dwRv;  
}