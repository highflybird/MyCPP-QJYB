// QJYB.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "QJYB.h"
#include "QJYBDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQJYBApp

BEGIN_MESSAGE_MAP(CQJYBApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CQJYBApp ����

CQJYBApp::CQJYBApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CQJYBApp ����

CQJYBApp theApp;


// CQJYBApp ��ʼ��

BOOL CQJYBApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(_T("��ʼ��OLEʧ�ܣ�"));
		return FALSE;
	}

	AfxEnableControlContainer();

	BOOL bExist = FALSE;
#ifdef _WIN64
	HANDLE hMutex = ::CreateMutex(NULL,TRUE,_T("QJYB.x64"));
#else
	HANDLE hMutex = ::CreateMutex(NULL,TRUE,_T("QJYB.x32"));
#endif

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		bExist = TRUE;
	}
	if (hMutex)
	{
		::ReleaseMutex(hMutex);
	}
	if(bExist)
	{
		//AfxMessageBox(_T("ֻ������һ��ʵ��"));
		return FALSE;
	}

	//CoInitializeEx(NULL,COINIT_APARTMENTTHREADED); //COINIT_MULTITHREADED
	CoInitialize(NULL);

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CQJYBDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	CoUninitialize();
	return FALSE;
}
