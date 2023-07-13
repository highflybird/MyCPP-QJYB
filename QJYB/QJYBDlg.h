// QJYBDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#define WM_SHOWTASK  WM_USER + 1000 
#define WM_RECVDATA  WM_USER + 1971
#define WM_FINISHED  WM_USER + 9999
#define WM_REFRESH	 WM_USER + 2019

//读取SDE数据
static UINT thread_ReadInfo(LPVOID pParamThread);
//循环检查
static UINT thread_ReadInfo2(LPVOID pParamThread);
//定时线程
static UINT thread_ReadInfo3(LPVOID pParamThread);

// CQJYBDlg 对话框
class CQJYBDlg : public CDialog
{
// 构造
public:
	CQJYBDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_QJYB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON			m_hIcon;
	NOTIFYICONDATA	m_nid;
	WINDOWPLACEMENT m_wp;
    bool            m_isBusy;
	bool            m_NotifyIconRemoved;
	int				m_current_sel;
	CComboBox		m_combo_CAD;
	CStatic			m_message;
	BOOL			m_includeSubDirectory;
    CString         m_strCurrentWindow;
	CRect			m_rect; 
	//
	WNDINFO         m_currentCAD;
    DWORD           m_currentID;
	MapProcessIDToWndinfo m_WndSet;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDisplay();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedOk();
	afx_msg void OnQuit();
	afx_msg void OnShow();
	afx_msg void OnAbout();
	afx_msg void OnClose();
	afx_msg void OnBnClickedOpenDir();
	afx_msg void OnBnClickedOpenFile();
	afx_msg void OnOpen();
	afx_msg void OnOpendir();
	afx_msg void OnCbnSelchangeComboCad();
	afx_msg LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);;
	afx_msg LRESULT OnRefresh(WPARAM wParam,LPARAM lParam);
	void StartServer();
	void Start();
	void AddNotifyIcon();
	void AutoRefresh();
	bool InitVLISP(WNDINFO & wi);
	bool beginLinkToCAD(WNDINFO &wndinfo);
	BOOL CheckDBX(WNDINFO &wi);
	BOOL DBXOpenFile (CString fileName);
	//报告错误,并赋值变量
	CString ReportError(CObject *e,WNDINFO *pWI = NULL);
	CString ReportError(CObject *e,VARIANT & va,WNDINFO *pWI = NULL);
	CString ReportError(exception *e,WNDINFO *pWI = NULL);
	
public:
 
	
};
