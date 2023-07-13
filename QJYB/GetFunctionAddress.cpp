#include "StdAfx.h"
#include "GetFunctionAddress.h"

FARPROC LoadFuncBase(LPCTSTR fileName,LPCSTR lpProcName ,HMODULE & hDLL)
{
	int retError=0;
	FARPROC p = NULL;	
	for (int i = 0;i < 256;i++)
	{
		hDLL = LoadLibraryEx(fileName,0,i);
		p = GetProcAddress(hDLL,lpProcName);
		if (p == NULL)
		{
			retError = GetLastError();
			FreeLibrary(hDLL);
			continue;
		}
		else
		{
			FreeLibrary(hDLL);
			break;
		}
	}
	return p;
}

BOOL CheckFunction(PCHAR pf)
{
	int iCount=strlen(pf);

	for(int i=0;i<iCount;i++)
	{
		if ((pf[i]<'0')||(pf[i]>'z')) return FALSE;
	}
	return TRUE;
}

//通过文件得到函数输出表
int getFuncAddr(LPCTSTR szFileName,FUNCTION_ADDRESS &funcSet)
{
	PIMAGE_NT_HEADERS nt_headers;
	PIMAGE_EXPORT_DIRECTORY export_data;
	DWORD export_data_size;
	PDWORD FunctionsNames,FunctionsPtrs;
	PWORD NameOrdinals;
	HANDLE hFile,hFileMap;
	DWORD file_attributes;
	PVOID mod_base,func_ptr=0,image_base;
	TCHAR file_path[MAX_PATH];
	char * func_name = NULL;
	LPWIN32_FIND_DATA lpwfd_first=new WIN32_FIND_DATA;
	DWORD i(0),dwretcode;
	TCHAR lpTmp[MAX_PATH];
	BOOLEAN bcp=FALSE;

	//GetFullPathName (argv[1],MAX_PATH,file_path ,NULL);
	_stprintf(file_path,szFileName);;
	if (FindFirstFile (file_path,lpwfd_first)==NULL)
	{
		//file_attributes=0;
		_tprintf(_T("读取文件失败!"));
		return 0;
	}
	else
	{
		file_attributes=lpwfd_first->dwFileAttributes ;
	}
	
goto_continue:
	hFile=CreateFile(file_path,GENERIC_READ,0,0,OPEN_EXISTING,file_attributes,0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		dwretcode=GetLastError();
		if (!bcp && dwretcode==32)
		{
			bcp = TRUE;           //错了一次就不要再弄了
			_stprintf(lpTmp,szFileName);
			lpTmp[(_tcsrchr(szFileName,92) - szFileName)+1] = NULL;
			_stprintf(lpTmp,_T("%scopy.%d.%s"),lpTmp,++i,lpwfd_first->cFileName) ;
			CopyFile(szFileName,lpTmp,TRUE);
			_stprintf(file_path,lpTmp);
			goto goto_continue;
		}
		else 
		{
			_tprintf(_T("无效的文件或者无法打开!"));
			return 0;
		}
	}

	delete lpwfd_first;

	hFileMap=CreateFileMapping(hFile,0,PAGE_READONLY,0,0,0);
	if (hFileMap==NULL)
	{
		_tprintf(_T("Create File Map Error!\n"));
		CloseHandle(hFile);
		return 0;
	}
	mod_base =MapViewOfFile(hFileMap,FILE_MAP_READ,0,0,0);
	if (mod_base==NULL)
	{
		_tprintf(_T("Create MapView of file error!\n"));
		CloseHandle(hFileMap);
		CloseHandle(hFile);
		return 0;
	}
	nt_headers =ImageNtHeader (mod_base);
	image_base=(PVOID)nt_headers->OptionalHeader .ImageBase ;

	export_data =(PIMAGE_EXPORT_DIRECTORY )ImageDirectoryEntryToData (mod_base,
		FALSE,IMAGE_DIRECTORY_ENTRY_EXPORT,&export_data_size);
	if (export_data==NULL)
	{
		DWORD dwError = GetLastError();
		_tprintf(_T("ImageDirectoryEntryToData Error!(Errorcode:%d)\n"),dwError);
		CloseHandle(hFileMap);
		CloseHandle(hFile);
		return 0;
	}
	FunctionsNames =(PDWORD)ImageRvaToVa (nt_headers,mod_base,
		(DWORD)export_data->AddressOfNames ,0);
	FunctionsPtrs = (PDWORD)ImageRvaToVa(nt_headers,mod_base,
		(DWORD)export_data->AddressOfFunctions ,0);
	NameOrdinals =(PWORD)ImageRvaToVa(nt_headers,mod_base,
		(DWORD)export_data->AddressOfNameOrdinals ,0);

	//_tprintf(_T("Order FunctionName FunctionAddress\n"));
	INT_PTR funAddr = 0;
	int num = 0;
	for (i=0;i<export_data->NumberOfFunctions ;i++)
	{
		func_name = (PCHAR)ImageRvaToVa(nt_headers,mod_base,(DWORD)FunctionsNames[i],0);
		if (IsBadReadPtr (func_name,1))
			continue;
		if (IsBadCodePtr ((FARPROC)func_name))
			continue;
		if (IsBadReadPtr(&FunctionsPtrs[NameOrdinals[i]],1))
			continue;
		//if ((!IsCharAlpha (func_name[0]))&&(!IsCharAlphaNumeric (func_name[0])))
		//	continue;
		//if (!CheckFunction (func_name)) 
		//	continue;
		// func_ptr=NULL;
		func_ptr = (PVOID) FunctionsPtrs [NameOrdinals [i]];
		funcSet[func_name] = (INT_PTR)func_ptr;
		num++;
	}
 
	UnmapViewOfFile (mod_base);
	CloseHandle(hFileMap);
	CloseHandle(hFile);
	if (bcp)  
		DeleteFile(file_path);
	return num;
}
