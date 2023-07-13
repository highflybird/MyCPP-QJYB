// QJYBDlg.cpp : ʵ���ļ�
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

//��ȡSDE����
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

//ѭ�����
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
		m_message.SetWindowText(_T("û�����е�CAD���̣�"));
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
 
	//���������
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
			m_message.SetWindowText(_T("û�����е�CAD���̣�"));
		}
		m_combo_CAD.SetCurSel(0);
		m_current_sel=0;
	}
}
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CQJYBDlg �Ի���


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


// CQJYBDlg ��Ϣ�������

BOOL CQJYBDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_hWnd = GetSafeHwnd();
	AddNotifyIcon();//�������ͼ��

	//���ô���״̬Ϊ����
	GetWindowPlacement(&m_wp);							// �ָ�ʱ��
	GetWindowRect(&m_rect);  
	ShowWindow(SW_HIDE);
	//������δ�����Ϊ�˲���˸
	WINDOWPLACEMENT wp;
	wp.length = sizeof(WINDOWPLACEMENT);
	wp.flags = WPF_RESTORETOMAXIMIZED;
	wp.showCmd = SW_HIDE;
	SetWindowPlacement(&wp);

	UpdateData(FALSE);

	Start();
	RunModalLoop();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
//���ϵͳ����ͼ��
//////////////////////////////////////////////////////////////////////////
void CQJYBDlg::AddNotifyIcon()
{
	//������ʾ//
	m_nid.cbSize  = sizeof(NOTIFYICONDATA);
	m_nid.hWnd    = GetSafeHwnd();
	m_nid.uID     = IDR_MAINFRAME;						//��������Ϣ�е�wParam����
	m_nid.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
	m_nid.uCallbackMessage = WM_SHOWTASK;				// �Զ������Ϣ����//�������ͼ��ϵͳ��������Ϣ������������Ϣ�е�lParam������
	m_nid.hIcon   = m_hIcon;
	/*m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));*/
	_tcscpy(m_nid.szTip, _T("�߷���ȥ������"));		// ��Ϣ��ʾ��Ϊ"����������"��VS2008 UNICODE������wcscpy_s()����
	_tcscpy(m_nid.szInfoTitle, _T("�������"));
	_tcscpy(m_nid.szInfo, _T("��Ȩ����:�������"));
	Shell_NotifyIcon(NIM_ADD, &m_nid);					// �����������ͼ��
}

//////////////////////////////////////////////////////////////////////////
//����ͼ��Ĳ˵��������Ӧ
//////////////////////////////////////////////////////////////////////////
LRESULT CQJYBDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
	if(wParam != IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
	case WM_RBUTTONUP:									// �Ҽ�����ʱ�����˵�
		{
			CPoint pos;
			::GetCursorPos(&pos);						// �õ����λ��
			CMenu menu;				
			menu.LoadMenu(IDR_MENU1);					// �õ��������˵�
			CMenu *pMenu = menu.GetSubMenu(0);
			pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,pos.x ,pos.y, this);
			PostMessage(WM_NULL,0,0);
			pMenu->DestroyMenu();
			menu.DestroyMenu();
		}
		break;
	case WM_LBUTTONDBLCLK:								// ˫������Ĵ���
		OnDisplay();
		break;
	default:
		break;
	}
	return 0;
}

//�л�������ʾ
void CQJYBDlg::OnDisplay()
{
	// TODO: Add your command handler code here
	SetWindowPos(&wndNoTopMost,m_rect.left,m_rect.top,m_rect.right,m_rect.bottom,SWP_SHOWWINDOW); 
	SetWindowPlacement(&m_wp); 
	ShowWindow(SW_SHOWNORMAL);						// ��ʾ������
	SetForegroundWindow();
	SetActiveWindow();
	//::BringWindowToTop(m_hWnd);
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CQJYBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CQJYBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//////////////////////////////////////////////////////////////////////////
//�Զ�ˢ��CAD����
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

	//ˢ��CAD����
	int numberOfAutoCAD = FindProcessByName(_T("acad.exe"),m_WndSet);
	if (m_WndSet.size() == 0)
	{
		m_message.SetWindowText(_T("û�����е�CAD���̣�"));
		m_combo_CAD.ResetContent();
		m_current_sel = -1;
		m_currentCAD = WNDINFO();
		m_currentID = 0;
		m_strCurrentWindow.Empty();
		return FALSE;
	}
    
	//��������
	MapProcessIDToWndinfo::iterator itr = m_WndSet.begin();
	for (;itr!=m_WndSet.end();)
	{
		HANDLE hProcess = OpenProcess(PROCESS_VM_READ|PROCESS_QUERY_INFORMATION,FALSE,itr->second.dwProcessId);
		if (hProcess == NULL || hProcess == INVALID_HANDLE_VALUE)
		{
			m_WndSet.erase(itr++);//CAD�رջ��߲��ܶ�д�ˡ� itr = m_WndSet.erase(itr);
			continue;
		}
		else
		{
			CloseHandle(hProcess);
			//����Ѿ��Ƴ��ˣ��������Ƴ�������
			if (!itr->second.isRemoved)
			{
				RemoveEducationStamp(itr->second);
			}
			itr++;
		}
	}

	//���¸�ֵCAD�����б�
	m_combo_CAD.ResetContent();
	m_combo_CAD.Clear();
	int i = 0;
	for (itr = m_WndSet.begin();itr!=m_WndSet.end();itr++,i++)
	{
		m_combo_CAD.AddString(itr->second.strWindowText);
		beginLinkToCAD(itr->second);//��ʼ����CAD
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
	//����Ҳ���ID�ˣ���ô˵��CAD�����˳���
	if (itr == m_WndSet.end() && m_WndSet.size()>0)
	{
		itr = m_WndSet.begin();
		m_combo_CAD.SetCurSel(0);
		m_currentCAD = itr->second;
		m_current_sel = 0;
		m_currentID = itr->second.dwProcessId;
		m_strCurrentWindow = itr->second.strWindowText;
	}
	m_message.SetWindowText(_T("CAD���Ӿ���!"));
	return TRUE;
}


//////////////////////////////////////////////////////////////////////////
//����CAD������CADͨ��
//////////////////////////////////////////////////////////////////////////
bool CQJYBDlg::beginLinkToCAD(WNDINFO &wndinfo)
{
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,wndinfo.dwProcessId);
	if(hProcess==NULL|| hProcess==INVALID_HANDLE_VALUE)
		return false;
	CloseHandle(hProcess);

	//���´�������
	wndinfo.strWindowText.GetBufferSetLength(MAX_PATH);	
	::GetWindowText(wndinfo.hWnd,wndinfo.strWindowText.GetBuffer(),MAX_PATH);
	wndinfo.strWindowText.ReleaseBuffer();

	//����Ѿ����ӵ�LISP�Ͳ�����ˢ�����
	if (wndinfo.isLinkedWithLisp)
	{
		return true;	
	}

	try
	{
		//�����û�Ƴ������棬���Ƴ�
		if(!wndinfo.isRemoved)
			RemoveEducationStamp(wndinfo);

		if (wndinfo.App == NULL)
		{
			//wndinfo.App.DetachDispatch();
			//������Ҫ����CADApplication����
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
					wndinfo.App.AttachDispatch(m_pDisp);	//��ǰ�Ǵ���������������
				}
			}	
			if (wndinfo.App == NULL)
			{
				int i = GetLastError();
				CString strError;
				GetLastErrorBox(m_hWnd,_T("�����ˣ�"),strError);
				m_message.SetWindowText(strError+_T("..װ��CADʧ��!"));
				wndinfo.isAttached  = false; 
				return false;
			}
		}
		//�����Ѿ���CAD����������
		wndinfo.isAttached =  true;
		//SendCommandToCAD(wndinfo,CString(_T("(vl-load-com)\n")));
		CheckDBX(wndinfo);
		//��ȡ��ǰ�ĵ�����
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
				_tprintf(_T("�Ҳ�����������غ�����������Ҫ�Թ���Ա������д˳��򣬻���CAD�汾��2015-2018."));
				return FALSE;
			}
			INT_PTR offsetAddr = itr->second;
			
			//pfnView = (acedGetAcadDwgView)((INT_PTR)wndinfo.hMod + offsetAddr); //�������ݿ�

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

//�������,����ֵ����
CString CQJYBDlg::ReportError(CObject *e,VARIANT & va,WNDINFO *pWI)
{
	CString strError = ReportError(e,pWI);
	va.vt = VT_BSTR;
	va.bstrVal = (strError.GetBuffer());
	return strError;
}

//�������
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

//�������
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

//DBX���ļ�
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
		m_message.SetWindowText(_T("����δ֪����!"));
	}
	m_isBusy = false;
	return FALSE;
}

//���DBX�Ƿ񴴽�
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
			m_message.SetWindowText(_T("��������DBX!"));
			return FALSE;
		}
	}
	return TRUE;
}

//���ļ�
void CQJYBDlg::OnBnClickedOpenFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] =_T("�ı��ļ�(*.dwg)|*.dwg|");
	CFileDialog dlg(TRUE, _T("dwg"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	CString szFileName ;
	if(dlg.DoModal() == IDOK && CheckDBX(m_currentCAD))
	{
		szFileName = dlg.GetPathName();
		m_message.SetWindowText(szFileName);
		DBXOpenFile(szFileName);
	}
}

//�õ��ļ�·���ĸ�ʽ��׺
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

// ����Ŀ¼��ĳһ�����ļ� (����Ŀ¼��Ŀ¼),˵������ʽformatӦ����*.XXX��dirӦ������\\��β
void FindDirAllFileEx(LPCTSTR dir, LPCTSTR format, vector<CString>& filePath ,BOOL isRecursive =TRUE)
{
	CFileFind fileFinder;
	CString path(dir);
	path.Append(format);

	BOOL bFinished = fileFinder.FindFile(path);
	while (bFinished)  //ÿ��ѭ����Ӧһ�����Ŀ¼
	{
		bFinished = fileFinder.FindNextFile();
		// ���� . �� .. ; �������������ѭ���У�����
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


// ����Ŀ¼��ĳһ�����ļ� (����Ŀ¼��Ŀ¼)    
void FindDirAllFileEx(wstring dir, vector<wstring> &format, vector<wstring>& filePath)
{
	CFileFind fileFinder;
	CString path = CString(dir.c_str()) + _T("\\*.*");

	BOOL bFinished = fileFinder.FindFile(path);
	while (bFinished)  //ÿ��ѭ����Ӧһ�����Ŀ¼
	{
		bFinished = fileFinder.FindNextFile();
		// ���� . �� .. ; �������������ѭ���У�����
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
			//��ȡ�ļ�����
			wstring file = fileFinder.GetFilePath().GetString();
			wstring postfix = GetPathFormat(file);
	 
			//for (auto it : format)  //��������﷨
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
	// TODO: �ڴ���������������
	OnBnClickedOpenFile();
}

void CQJYBDlg::OnBnClickedOpenDir()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!CheckDBX(m_currentCAD))
	{
		return;
	}
 
	static TCHAR strDirName[MAX_PATH];
	BROWSEINFO bi;
	CString szString = TEXT("ѡ��һ��Դ�ļ����ļ���");
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
			m_message.SetWindowText(files[i]+_T(" ����ɹ���"));
		}
		else
		{
			m_message.SetWindowText(files[i]+_T(" ����ʧ�ܣ�"));
		}
	}
}

void CQJYBDlg::OnOpendir()
{
	// TODO: �ڴ���������������
	OnBnClickedOpenDir();
}

//////////////////////////////////////////////////////////////////////////
//��ʼ��LISP
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
			utility.Prompt(_T("��ʼ��LISPʧ��!\n"));
			m_message.SetWindowText(_T("��ʼ��LISPʧ��!"));
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
		utility.Prompt(_T("��ȡ��ǰ�ĵ�ʧ��!\n"));
		m_message.SetWindowText(_T("��ȡ��ǰ�ĵ�ʧ��!"));
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
		utility.Prompt(_T("��ȡLISP����ʧ��!\n"));
		m_message.SetWindowText(_T("��ȡLISP����ʧ��!!"));
		wi.isLinkedWithLisp = false;
		return false;
	}
	wi.isLinkedWithLisp = true;
	m_message.SetWindowText(_T("���Ӿ���!"));
	return true;
}

void CQJYBDlg::OnBnClickedRefresh()
{
	BOOL ret = OnRefresh(WM_REFRESH,(LPARAM)&m_WndSet);
	if (!ret)
	{
		m_message.SetWindowText(_T("����δ�ɹ���"));
	}
}

void CQJYBDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	// ��������ɾ��ͼ��
	if (!m_NotifyIconRemoved)
	{
		Shell_NotifyIcon(NIM_DELETE, &m_nid); 
		m_NotifyIconRemoved = true;
	}
}

void CQJYBDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if(nType == SIZE_MINIMIZED)  
	{  
		ShowWindow(SW_HIDE); // ����С���У�����������              
	}  
}

void CQJYBDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnOK();
	ShowWindow(SW_HIDE);
}

void CQJYBDlg::OnQuit()
{
	// TODO: �ڴ���������������
	OnCancel();
}

void CQJYBDlg::OnShow()
{
	// TODO: �ڴ���������������
	OnDisplay();
}

void CQJYBDlg::OnAbout()
{
	// TODO: �ڴ���������������
	CAboutDlg  dlg;
	dlg.DoModal();
}

void CQJYBDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int ret = MessageBox(_T("1.��С����ϵͳ����[��(Y)] \n2.�˳�����[��(N)]"),_T("\n��Ҫ��ʲô��"),MB_YESNO);
	if (ret == IDYES)
	{
		ShowWindow(SW_HIDE);
		return;
	}

	CDialog::OnClose();
}



void CQJYBDlg::OnCbnSelchangeComboCad()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
