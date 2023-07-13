// QJYBDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "QJYB.h"
#include "QJYBDlg.h"
#include "GetProcess.h"
#include "RemoveEDU.h"
#include "GetFunctionAddress.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//读取SDE数据
static UINT thread_ReadInfo(LPVOID pParamThread)
{
	//m_mutex1.Lock();
	try
	{
		CQJYBDlg* pDialog=(CQJYBDlg*)pParamThread;
		pDialog->StartServer();
	}
	catch(...)
	{

	}
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//m_mutex1.Unlock();
	return 0;
}

//循环检查
static UINT thread_ReadInfo2(LPVOID pParamThread)
{
	//m_mutex1.Lock();
	try
	{
		CQJYBDlg* pDialog = (CQJYBDlg*)pParamThread;
		pDialog->AutoRefresh();
	}
	catch (CException* e)
	{
		e->ReportError();
		delete e;
		e = NULL;
	}
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//m_mutex1.Unlock();
	return 0;
}

bool IsProcessStillActive(DWORD dwProcessId)
{
	HANDLE hProcess=OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,dwProcessId);
	if(hProcess==NULL||hProcess==INVALID_HANDLE_VALUE)
		return false;
	DWORD ExitCode=0;
	GetExitCodeProcess(hProcess,&ExitCode);
	CloseHandle(hProcess);
	return ExitCode==STILL_ACTIVE;
}

CWinThread* pThread1 = NULL;
CWinThread* pThread2 = NULL;
CWinThread* pThread3 = NULL;

void CQJYBDlg::Start()
{
	UpdateData();

	int num = FindProcessByName(_T("acad.exe"),m_WndSet);
	if (m_WndSet.size() == 0)
	{
		m_message.SetWindowText(_T("没有运行的CAD进程！"));
		//return TRUE;
	}
	else
	{
		MapProcessIDToWndinfo::iterator itr =m_WndSet.begin();
		for (;itr!=m_WndSet.end();itr++)
		{
			m_combo_CAD.AddString(itr->second.strWindowText);
			beginLinkToCAD(itr->second);
		}
		itr = m_WndSet.begin();
		m_combo_CAD.SetCurSel(0);
		m_current_sel = 0;
		m_combo_CAD.GetLBText(0,m_strCurrentWindow);
		m_currentCAD = itr->second;
		m_currentID = itr->second.dwProcessId;
	}
 
	//开启服务端
	if (pThread1 != NULL)
	{
		DWORD exitCode = 0;
		GetExitCodeThread(pThread1->m_hThread,&exitCode);
		if (exitCode == STILL_ACTIVE)
			return;
	}	

	//pThread1 = AfxBeginThread(thread_ReadInfo,this);
	pThread1 = AfxBeginThread(thread_ReadInfo2,this);

}

void CQJYBDlg::StartServer()
{
	//UpdateData();
	if (m_WndSet.size()==0)
	{
		::PostMessage(m_hWnd,WM_REFRESH,0,(LPARAM)&m_WndSet);
		Sleep(500);
		if (m_WndSet.size()==0)
		{
			m_message.SetWindowText(_T("没有运行的CAD进程！"));
		}
		m_combo_CAD.SetCurSel(0);
		m_current_sel=0;
	}
}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CQJYBDlg 对话框


CQJYBDlg::CQJYBDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQJYBDlg::IDD, pParent)
	, m_current_sel(-1)
	, m_includeSubDirectory(FALSE)
	, m_isBusy(false)
	, m_currentID(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQJYBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_COMBO_CAD, m_strCurrentWindow);
	//DDX_Text(pDX, IDC_COMBO_CAD, m_combo_CAD);
	DDX_Control(pDX, IDC_COMBO_CAD, m_combo_CAD);
	DDX_CBIndex(pDX, IDC_COMBO_CAD, m_current_sel);
	DDX_Control(pDX, IDC_MESSAGE, m_message);
	DDX_Check(pDX, IDC_CHECK_SUBDIR, m_includeSubDirectory);
}

BEGIN_MESSAGE_MAP(CQJYBDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SHOWTASK, OnShowTask)
	ON_MESSAGE(WM_REFRESH,OnRefresh)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_REFRESH, OnBnClickedRefresh)
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_COMMAND(ID_QUIT, OnQuit)
	ON_COMMAND(ID_SHOW, OnShow)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_OPENDIR, OnBnClickedOpenDir)
	ON_BN_CLICKED(IDC_OPENFILE, OnBnClickedOpenFile)
	ON_COMMAND(ID_OPEN,  OnOpen)
	ON_COMMAND(ID_OPENDIR, OnOpendir)
	ON_CBN_SELCHANGE(IDC_COMBO_CAD, &CQJYBDlg::OnCbnSelchangeComboCad)
END_MESSAGE_MAP()


// CQJYBDlg 消息处理程序

BOOL CQJYBDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	m_hWnd = GetSafeHwnd();
	AddNotifyIcon();//添加托盘图标

	//设置窗口状态为隐藏
	GetWindowPlacement(&m_wp);							// 恢复时用
	GetWindowRect(&m_rect);  
	ShowWindow(SW_HIDE);
	//下面这段代码是为了不闪烁
	WINDOWPLACEMENT wp;
	wp.length = sizeof(WINDOWPLACEMENT);
	wp.flags = WPF_RESTORETOMAXIMIZED;
	wp.showCmd = SW_HIDE;
	SetWindowPlacement(&wp);

	UpdateData(FALSE);

	Start();
	RunModalLoop();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CQJYBDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

//////////////////////////////////////////////////////////////////////////
//添加系统托盘图标
//////////////////////////////////////////////////////////////////////////
void CQJYBDlg::AddNotifyIcon()
{
	//托盘显示//
	m_nid.cbSize  = sizeof(NOTIFYICONDATA);
	m_nid.hWnd    = GetSafeHwnd();
	m_nid.uID     = IDR_MAINFRAME;						//发出的消息中的wParam参数
	m_nid.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
	m_nid.uCallbackMessage = WM_SHOWTASK;				// 自定义的消息名称//点击托盘图标系统发出的消息（即发出的消息中的lParam参数）
	m_nid.hIcon   = m_hIcon;
	/*m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));*/
	_tcscpy(m_nid.szTip, _T("高飞鸟去教育版"));		// 信息提示条为"服务器程序"，VS2008 UNICODE编码用wcscpy_s()函数
	_tcscpy(m_nid.szInfoTitle, _T("飞鸟软件"));
	_tcscpy(m_nid.szInfo, _T("版权所有:飞鸟软件"));
	Shell_NotifyIcon(NIM_ADD, &m_nid);					// 在托盘区添加图标
}

//////////////////////////////////////////////////////////////////////////
//托盘图标的菜单和鼠标响应
//////////////////////////////////////////////////////////////////////////
LRESULT CQJYBDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
	if(wParam != IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
	case WM_RBUTTONUP:									// 右键起来时弹出菜单
		{
			CPoint pos;
			::GetCursorPos(&pos);						// 得到鼠标位置
			CMenu menu;				
			menu.LoadMenu(IDR_MENU1);					// 得到程序主菜单
			CMenu *pMenu = menu.GetSubMenu(0);
			pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,pos.x ,pos.y, this);
			PostMessage(WM_NULL,0,0);
			pMenu->DestroyMenu();
			menu.DestroyMenu();
		}
		break;
	case WM_LBUTTONDBLCLK:								// 双击左键的处理
		OnDisplay();
		break;
	default:
		break;
	}
	return 0;
}

//切换正常显示
void CQJYBDlg::OnDisplay()
{
	// TODO: Add your command handler code here
	SetWindowPos(&wndNoTopMost,m_rect.left,m_rect.top,m_rect.right,m_rect.bottom,SWP_SHOWWINDOW); 
	SetWindowPlacement(&m_wp); 
	ShowWindow(SW_SHOWNORMAL);						// 显示主窗口
	SetForegroundWindow();
	SetActiveWindow();
	//::BringWindowToTop(m_hWnd);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CQJYBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CQJYBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//////////////////////////////////////////////////////////////////////////
//自动刷新CAD进程
//////////////////////////////////////////////////////////////////////////
void CQJYBDlg::AutoRefresh()
{ 
	while(true)
	{
		if (!m_isBusy)
		{
			::PostMessage(m_hWnd,WM_REFRESH,0,(LPARAM)&m_WndSet);
		}
		Sleep(5000);
	}
}

LRESULT CQJYBDlg::OnRefresh(WPARAM wParam,LPARAM lParam)
{
	UpdateData();
	if (m_isBusy)
	{
		return FALSE;
	}

	//刷新CAD进程
	int numberOfAutoCAD = FindProcessByName(_T("acad.exe"),m_WndSet);
	if (m_WndSet.size() == 0)
	{
		m_message.SetWindowText(_T("没有运行的CAD进程！"));
		m_combo_CAD.ResetContent();
		m_current_sel = -1;
		m_currentCAD = WNDINFO();
		m_currentID = 0;
		m_strCurrentWindow.Empty();
		return FALSE;
	}
    
	//遍历进程
	MapProcessIDToWndinfo::iterator itr = m_WndSet.begin();
	for (;itr!=m_WndSet.end();)
	{
		HANDLE hProcess = OpenProcess(PROCESS_VM_READ|PROCESS_QUERY_INFORMATION,FALSE,itr->second.dwProcessId);
		if (hProcess == NULL || hProcess == INVALID_HANDLE_VALUE)
		{
			m_WndSet.erase(itr++);//CAD关闭或者不能读写了。 itr = m_WndSet.erase(itr);
			continue;
		}
		else
		{
			CloseHandle(hProcess);
			//如果已经移除了，无需再移除教育版
			if (!itr->second.isRemoved)
			{
				RemoveEducationStamp(itr->second);
			}
			itr++;
		}
	}

	//重新赋值CAD进程列表
	m_combo_CAD.ResetContent();
	m_combo_CAD.Clear();
	int i = 0;
	for (itr = m_WndSet.begin();itr!=m_WndSet.end();itr++,i++)
	{
		m_combo_CAD.AddString(itr->second.strWindowText);
		beginLinkToCAD(itr->second);//开始连接CAD
		if (itr->second.dwProcessId == m_currentID)
		{
			m_combo_CAD.SetCurSel(i);
			m_currentCAD = itr->second;
			m_current_sel = i;
			m_currentID = itr->second.dwProcessId;
			m_strCurrentWindow = itr->second.strWindowText;
		}
	}

	itr = m_WndSet.find(m_currentID);
	//如果找不到ID了，那么说明CAD可能退出了
	if (itr == m_WndSet.end() && m_WndSet.size()>0)
	{
		itr = m_WndSet.begin();
		m_combo_CAD.SetCurSel(0);
		m_currentCAD = itr->second;
		m_current_sel = 0;
		m_currentID = itr->second.dwProcessId;
		m_strCurrentWindow = itr->second.strWindowText;
	}
	m_message.SetWindowText(_T("CAD连接就绪!"));
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////
//连接CAD，并与CAD通信
//////////////////////////////////////////////////////////////////////////
bool CQJYBDlg::beginLinkToCAD(WNDINFO &wndinfo)
{
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,wndinfo.dwProcessId);
	if(hProcess==NULL|| hProcess==INVALID_HANDLE_VALUE)
		return false;
	CloseHandle(hProcess);

	//更新窗口文字
	wndinfo.strWindowText.GetBufferSetLength(MAX_PATH);	
	::GetWindowText(wndinfo.hWnd,wndinfo.strWindowText.GetBuffer(),MAX_PATH);
	wndinfo.strWindowText.ReleaseBuffer();

	//如果已经连接到LISP就不用再刷新这个
	if (wndinfo.isLinkedWithLisp)
	{
		return true;	
	}

	try
	{
		//如果还没移除教育版，则移除
		if(!wndinfo.isRemoved)
			RemoveEducationStamp(wndinfo);

		if (wndinfo.App == NULL)
		{
			//wndinfo.App.DetachDispatch();
			//现在需要创建CADApplication对象
			CString strVersion;
			strVersion.Format(_T("AutoCAD.Application.%s"),wndinfo.strVersion.Mid(1,2));
			CLSID clsid;
			HRESULT hr = ::CLSIDFromProgID(strVersion,&clsid);
			IUnknown *m_pUnkn = NULL; 
			IDispatch *m_pDisp = NULL; 
			if (::GetActiveObject(clsid, NULL,&m_pUnkn) == S_OK)	
			{
				if (m_pUnkn->QueryInterface(IID_IDispatch, (void**)&m_pDisp) == S_OK)
				{
					wndinfo.App.AttachDispatch(m_pDisp);	//以前是创建，现在是连接
				}
			}	
			if (wndinfo.App == NULL)
			{
				int i = GetLastError();
				CString strError;
				GetLastErrorBox(m_hWnd,_T("出错了！"),strError);
				m_message.SetWindowText(strError+_T("..装入CAD失败!"));
				wndinfo.isAttached  = false; 
				return false;
			}
		}
		//现在已经与CAD建立了连接
		wndinfo.isAttached =  true;
		//SendCommandToCAD(wndinfo,CString(_T("(vl-load-com)\n")));
		CheckDBX(wndinfo);
		//获取当前文档对象
		if (wndinfo.ActiveDoc.m_lpDispatch == NULL)
		{
			wndinfo.ActiveDoc = wndinfo.App.get_ActiveDocument();
			if (!wndinfo.ActiveDoc)
				return false;
			wndinfo.ActiveDoc.SendCommand(_T("(vl-load-com)\n"));
		}
#if 0
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, wndinfo.dwProcessId);

		LPCSTR szfnView = "?acedGetAcadDwgView@@YAPAVCView@@XZ";
		LPCSTR szfnData = "?AcApGetDatabase@@YAPAVAcDbDatabase@@PAVCView@@@Z";
		LPCSTR szfnDoc = "?acDocManagerPtr@@YAPAVAcApDocManager@@XZ";
		acedGetAcadDwgView pfnView = (acedGetAcadDwgView) GetProcAddress(wndinfo.hMod,szfnView);
		AcApGetDatabase pfnData = (AcApGetDatabase) GetProcAddress(wndinfo.hMod,szfnData);
		acDocManagerPtr pfnDoc = (acDocManagerPtr) GetProcAddress(wndinfo.hMod,szfnDoc);
		
		if (pfnView==NULL)
		{
			FUNCTION_ADDRESS funcSet;
			int ret = getFuncAddr(wndinfo.strAppPath,funcSet);
			//FUNCTION_ADDRESS::iterator itr = funcSet.find(szfnView); 
			FUNCTION_ADDRESS::iterator itr = funcSet.find(szfnDoc); 
			if (itr == funcSet.end())
			{
				_tprintf(_T("找不到教育版相关函数！可能需要以管理员身份运行此程序，或者CAD版本是2015-2018."));
				return FALSE;
			}
			INT_PTR offsetAddr = itr->second;
			
			//pfnView = (acedGetAcadDwgView)((INT_PTR)wndinfo.hMod + offsetAddr); //操纵数据库

			pfnDoc = (acDocManagerPtr)((INT_PTR)wndinfo.hMod + offsetAddr);

			void *p = NULL;//pfnDoc();
			_asm
			{
				mov eax,dword ptr ds:[0xD10068]
				mov dword ptr [p], eax
			}

			//
			int i = 1;
		}
		
		HWND  h = (HWND)wndinfo.ActiveDoc.get_HWND();
		h = ::GetWindow(h,GW_CHILD);
		h = ::GetWindow(h,GW_HWNDNEXT);	
		//CView  *view = (CView *) CWnd::FromHandle(h);
		LPVOID view = pfnView();
		PVOID pDatabase = pfnData((CView *)view);
#endif

		return InitVLISP(wndinfo);
	}
	catch(COleDispatchException *e)
	{
		ReportError(e,&wndinfo);
		return false;
	}
	catch (CMemoryException* e)
	{
		ReportError(e,&wndinfo);
		return false;
	}
	catch (CFileException* e)
	{
		ReportError(e,&wndinfo);
		return false;
	}
	catch (CException* e)
	{
		ReportError(e,&wndinfo);
		return false;
	}
	catch (exception* e)
	{
		ReportError(e,&wndinfo);
		return false;
	}
}

//报告错误,并赋值变量
CString CQJYBDlg::ReportError(CObject *e,VARIANT & va,WNDINFO *pWI)
{
	CString strError = ReportError(e,pWI);
	va.vt = VT_BSTR;
	va.bstrVal = (strError.GetBuffer());
	return strError;
}

//报告错误
CString CQJYBDlg::ReportError(CObject *e,WNDINFO *pWI)
{
	TCHAR error[BUFSIZ]={0};
	if (e->IsKindOf(RUNTIME_CLASS(CException)))
		((CException*)e)->GetErrorMessage(error,BUFSIZ);
	else 
		if (e->IsKindOf(RUNTIME_CLASS(CMemoryException)))
			((CMemoryException*)e)->GetErrorMessage(error,BUFSIZ);
		else 
			if (e->IsKindOf(RUNTIME_CLASS(COleDispatchException)))
				((COleDispatchException*)e)->GetErrorMessage(error,BUFSIZ);
			else
				if (e->IsKindOf(RUNTIME_CLASS(CFileException)))
					((CFileException*)e)->GetErrorMessage(error,BUFSIZ);  

	m_message.SetWindowText(error);
	if (pWI && pWI->ActiveDoc)
	{
		CAcadUtility uti=pWI->ActiveDoc.get_Utility();
		uti.Prompt(error);
	}
	return CString(error);
}

//报告错误
CString CQJYBDlg::ReportError(exception *e,WNDINFO *pWI)
{
	CString error(e->what());
	m_message.SetWindowText(error);
	if (pWI && pWI->ActiveDoc)
	{
		CAcadUtility uti=pWI->ActiveDoc.get_Utility();
		uti.Prompt(error);
	}
	return error;
}

//DBX打开文件
BOOL CQJYBDlg::DBXOpenFile (CString szFileName)
{
	CString str;
	str.GetBufferSetLength(512);
	try
	{
		m_isBusy = true;
		m_currentCAD.DBX.Open(szFileName);
		szFileName = szFileName.Mid(0,szFileName.GetLength()-3);
		szFileName = szFileName+_T("Copy.dwg");
		m_currentCAD.DBX.SaveAs(szFileName);
		m_isBusy = false;
		return TRUE;
	}
    
	catch(COleDispatchException *e)
	{
		ReportError(e,&m_currentCAD);
	}
	catch (CMemoryException* e)
	{
		ReportError(e,&m_currentCAD);
	}
	catch (CFileException* e)
	{
		ReportError(e,&m_currentCAD);
	}
	catch (CException* e)
	{
		ReportError(e,&m_currentCAD);
	}
	catch (exception* e)
	{
		ReportError(e,&m_currentCAD);
	}
	catch (...)
	{
		m_message.SetWindowText(_T("遇到未知错误!"));
	}
	m_isBusy = false;
	return FALSE;
}

//检查DBX是否创建
BOOL CQJYBDlg::CheckDBX(WNDINFO &wi)
{
	if(wi.App && wi.DBX == NULL)
	{
		CString strVersion;
		strVersion.Format(_T("ObjectDBX.AxDbDocument.%s"),wi.strVersion.Mid(1,2));
		m_isBusy = true;
	    wi.DBX = wi.App.GetInterfaceObject(strVersion);
		m_isBusy = false;
		if (wi.DBX == NULL)
		{
			m_message.SetWindowText(_T("不能连接DBX!"));
			return FALSE;
		}
	}
	return TRUE;
}

//打开文件
void CQJYBDlg::OnBnClickedOpenFile()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] =_T("文本文件(*.dwg)|*.dwg|");
	CFileDialog dlg(TRUE, _T("dwg"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	CString szFileName ;
	if(dlg.DoModal() == IDOK && CheckDBX(m_currentCAD))
	{
		szFileName = dlg.GetPathName();
		m_message.SetWindowText(szFileName);
		DBXOpenFile(szFileName);
	}
}

//得到文件路径的格式后缀
wstring GetPathFormat(wstring filePath)
{
	wstring format = filePath;
	size_t p = filePath.find_last_of('.');
	if (p == -1)
	{
		return wstring();
	}
	format.erase(0, p);
	return format;
}

// 查找目录下某一类型文件 (遍历目录的目录),说明：格式format应该是*.XXX，dir应该是以\\结尾
void FindDirAllFileEx(LPCTSTR dir, LPCTSTR format, vector<CString>& filePath ,BOOL isRecursive =TRUE)
{
	CFileFind fileFinder;
	CString path(dir);
	path.Append(format);

	BOOL bFinished = fileFinder.FindFile(path);
	while (bFinished)  //每次循环对应一个类别目录
	{
		bFinished = fileFinder.FindNextFile();
		// 跳过 . 和 .. ; 否则会陷入无限循环中！！！
		if (fileFinder.IsDots())
		{
			continue;
		}

		if (!fileFinder.IsDirectory())
		{
			filePath.push_back(fileFinder.GetFilePath().GetString());
		}
		else if (isRecursive)
		{
			FindDirAllFileEx(fileFinder.GetFilePath().GetString(), format, filePath);
		}
	}

	fileFinder.Close();
}


// 查找目录下某一类型文件 (遍历目录的目录)    
void FindDirAllFileEx(wstring dir, vector<wstring> &format, vector<wstring>& filePath)
{
	CFileFind fileFinder;
	CString path = CString(dir.c_str()) + _T("\\*.*");

	BOOL bFinished = fileFinder.FindFile(path);
	while (bFinished)  //每次循环对应一个类别目录
	{
		bFinished = fileFinder.FindNextFile();
		// 跳过 . 和 .. ; 否则会陷入无限循环中！！！
		if (fileFinder.IsDots())
		{
			continue;
		}

		if (fileFinder.IsDirectory())
		{
			FindDirAllFileEx(fileFinder.GetFilePath().GetString(), format, filePath);
		}
		else
		{
			//获取文件类型
			wstring file = fileFinder.GetFilePath().GetString();
			wstring postfix = GetPathFormat(file);
	 
			//for (auto it : format)  //这个是新语法
			for (vector<wstring>::iterator it = format.begin();it!=format.end();it++)
			{
				if (_tcsicmp((*it).c_str(), postfix.c_str()) == 0)
				{
					filePath.push_back(file);
					break;
				}
			}
		}
	}

	fileFinder.Close();
}

void CQJYBDlg::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedOpenFile();
}

void CQJYBDlg::OnBnClickedOpenDir()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!CheckDBX(m_currentCAD))
	{
		return;
	}
 
	static TCHAR strDirName[MAX_PATH];
	BROWSEINFO bi;
	CString szString = TEXT("选择一个源文件子文件夹");
	bi.hwndOwner = ::GetFocus();
	bi.pidlRoot = NULL;
	bi.pszDisplayName = strDirName;
	bi.lpszTitle = szString;
	bi.ulFlags = BIF_BROWSEFORCOMPUTER | BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;


	LPITEMIDLIST pItemIDList = ::SHBrowseForFolder(&bi);
	if(pItemIDList == NULL)
	{
		return ;
	}


	::SHGetPathFromIDList(pItemIDList, strDirName);
	CString strPath = strDirName;
	if(strPath != "" && strPath.Right(1) != '\\')
		strPath += _T("\\");

	m_message.SetWindowText(strPath);

	vector<CString> files;
	FindDirAllFileEx(strPath,_T("*.dwg"),files,m_includeSubDirectory);
	BOOL isOK = FALSE;
	for (DWORD i = 0;i<files.size();i++)
	{
		isOK = DBXOpenFile(files[i]);
		if (isOK)
		{
			m_message.SetWindowText(files[i]+_T(" 处理成功！"));
		}
		else
		{
			m_message.SetWindowText(files[i]+_T(" 处理失败！"));
		}
	}
}

void CQJYBDlg::OnOpendir()
{
	// TODO: 在此添加命令处理程序代码
	OnBnClickedOpenDir();
}

//////////////////////////////////////////////////////////////////////////
//初始化LISP
//////////////////////////////////////////////////////////////////////////
bool CQJYBDlg::InitVLISP(WNDINFO & wi)
{
	if (wi.VLISP.m_lpDispatch == NULL  && wi.ActiveDoc)
	{
		wi.VLISP = wi.App.GetInterfaceObject(_T("VL.Application.16"));		
		if (wi.VLISP == NULL)
		{
			wi.VLISP = wi.App.GetInterfaceObject(_T("VL.Application.1"));		
		}
		if (wi.VLISP == NULL)
		{
			CAcadUtility utility  = wi.ActiveDoc.get_Utility();
			utility.Prompt(_T("初始化LISP失败!\n"));
			m_message.SetWindowText(_T("初始化LISP失败!"));
			wi.isLinkedWithLisp = false;
			return false;
		}
	}

	if (wi.vlActiveDocument == NULL)
	{
		wi.vlActiveDocument = wi.VLISP.get_ActiveDocument();
	}

	if (wi.vlActiveDocument == NULL)
	{
		CAcadUtility utility  = wi.ActiveDoc.get_Utility();
		utility.Prompt(_T("获取当前文档失败!\n"));
		m_message.SetWindowText(_T("获取当前文档失败!"));
		wi.isLinkedWithLisp = false;
		return false;
	}

	if (wi.vlFunctions == NULL)
	{
		wi.vlFunctions = wi.vlActiveDocument.get_Functions();
	}

	if (wi.vlFunctions == NULL)
	{
		CAcadUtility utility  = wi.ActiveDoc.get_Utility();
		utility.Prompt(_T("获取LISP函数失败!\n"));
		m_message.SetWindowText(_T("获取LISP函数失败!!"));
		wi.isLinkedWithLisp = false;
		return false;
	}
	wi.isLinkedWithLisp = true;
	m_message.SetWindowText(_T("连接就绪!"));
	return true;
}

void CQJYBDlg::OnBnClickedRefresh()
{
	BOOL ret = OnRefresh(WM_REFRESH,(LPARAM)&m_WndSet);
	if (!ret)
	{
		m_message.SetWindowText(_T("更新未成功！"));
	}
}

void CQJYBDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	// 在托盘区删除图标
	if (!m_NotifyIconRemoved)
	{
		Shell_NotifyIcon(NIM_DELETE, &m_nid); 
		m_NotifyIconRemoved = true;
	}
}

void CQJYBDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if(nType == SIZE_MINIMIZED)  
	{  
		ShowWindow(SW_HIDE); // 当最小化市，隐藏主窗口              
	}  
}

void CQJYBDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
	ShowWindow(SW_HIDE);
}

void CQJYBDlg::OnQuit()
{
	// TODO: 在此添加命令处理程序代码
	OnCancel();
}

void CQJYBDlg::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	OnDisplay();
}

void CQJYBDlg::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg  dlg;
	dlg.DoModal();
}

void CQJYBDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int ret = MessageBox(_T("1.最小化到系统托盘[是(Y)] \n2.退出程序[否(N)]"),_T("\n你要做什么："),MB_YESNO);
	if (ret == IDYES)
	{
		ShowWindow(SW_HIDE);
		return;
	}

	CDialog::OnClose();
}



void CQJYBDlg::OnCbnSelchangeComboCad()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
    int i = 0;
	for (MapProcessIDToWndinfo::iterator itr = m_WndSet.begin();itr!=m_WndSet.end();itr++,i++)
	{
		if (i==m_current_sel)
		{
			m_currentCAD = itr->second;
			m_currentID = itr->second.dwProcessId;
			m_strCurrentWindow = itr->second.strWindowText;
		}
	}
}
