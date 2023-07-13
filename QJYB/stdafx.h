// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// �� Windows ͷ���ų�����ʹ�õ�����
#endif

// ���������ʹ��������ָ����ƽ̨֮ǰ��ƽ̨�����޸�����Ķ��塣
// �йز�ͬƽ̨����Ӧֵ��������Ϣ����ο� MSDN��
#ifndef WINVER				// ����ʹ���ض��� Windows XP ����߰汾�Ĺ��ܡ�
#define WINVER 0x0501		// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif

#ifndef _WIN32_WINNT		// ����ʹ���ض��� Windows XP ����߰汾�Ĺ��ܡ�
#define _WIN32_WINNT 0x0501	// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif						

#ifndef _WIN32_WINDOWS		// ����ʹ���ض��� Windows 98 ����߰汾�Ĺ��ܡ�
#define _WIN32_WINDOWS 0x0410 // ��������Ϊ�ʺ� Windows Me ����߰汾����Ӧֵ��
#endif

#ifndef _WIN32_IE			// ����ʹ���ض��� IE 6.0 ����߰汾�Ĺ��ܡ�
#define _WIN32_IE 0x0600	// ����ֵ����Ϊ��Ӧ��ֵ���������� IE �������汾��ֵ��
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <map>
#include <vector>
#include <algorithm>
#include <imagehlp.h>
#include <string>
#include <strsafe.h>
#include <tchar.h>
#include <xstring>
#include <math.h>
#include <iostream>
#include <fstream>
#include <afxmt.h>	//ͬ������ʱ��Ҫ������ͷ�ļ�

#pragma comment(lib, "version.lib")
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "mscoree.lib")
#pragma comment(lib, "Dbghelp.lib")

#pragma warning(disable: 4995)
#pragma warning(disable: 4996)
#pragma warning(disable: 4267)  //possible loss of data ����
#pragma warning(disable: 4312)  //conversion from 'LONG' to 'HWND' of greater size ����
#pragma warning(disable: 4244)

using std::vector;
using namespace std;

#include ".\CAD\CAcadDocument.h"
#include ".\CAD\CAcadDocuments.h"
#include ".\CAD\CAcadApplication.h"
#include ".\CAD\CAcadUtility.h"
#include ".\CAD\CAcadDatabase.h"
#include ".\CAD\CAxDbDocument.h"

#include ".\LISP\CDVlApplication.h"
#include ".\LISP\CDVlApplicationEvents.h"
#include ".\LISP\CDVlDocument.h"
#include ".\LISP\CDVlDocuments.h"
#include ".\LISP\CDVlFunction.h"
#include ".\LISP\CDVlFunctions.h"
#include ".\LISP\CDVlObject.h"

//����һ������ID�ʹ��ھ���Ľṹ��
typedef class tagWNDINFO
{
public:
	DWORD				dwProcessId;		//���̺�
	bool				is64bit;			//�Ƿ�Ϊ64λ��CAD
	bool				isRemoved;			//�Ƿ��Ѿ������˽��������
	bool				isAttached;			//�Ƿ��CAD����������
	bool                isLinkedWithLisp;	//�Ƿ��LISP����������
	HWND				hWnd;				//CAD�Ĵ��ھ��
	HMODULE				hMod;				//acad.exeģ����ػ�ַ
	HMODULE				hAcDb;				//acdbXX.dllģ����ػ�ַ
	HMODULE				hAcCore;			//accore.dllģ����ػ�ַ		
	CString				strVersion;			//AutoCAD�汾��
	CString				strWindowText;		//CAD���ڱ���
	CString				strClassName;		//CAD����
	CString				strAppPath;			//acad.exe����ȫ·��
	CString				strAcDbPath;		//acdbXX.dllȫ·��
	CString				strAcCorePath;		//accore.dllȫ·��

	CAcadApplication	App;				//acad����
	CAcadDocument		ActiveDoc;			//��ǰ�ĵ�
	CAxDbDocument       DBX;
	CDVlApplication		VLISP;				//VLISP�������
	CDVlDocument		vlActiveDocument;	//VLISP�ĵ�ǰ�ĵ�
	CDVlFunctions		vlFunctions;		//VLISP��ȫ������
	CDVlFunction		vlFunction;			//VLISP��������
 
public:
	//���캯��
	tagWNDINFO():dwProcessId(0)
				,isRemoved(false)
				,isAttached(false)
				,is64bit(false)
				,isLinkedWithLisp(false)
				,hAcCore(NULL)
				,hAcDb(NULL)
				,hMod(NULL)
				,hWnd(NULL)
	{

	}
	//��������
	~tagWNDINFO() 
	{
		if(vlFunction.m_lpDispatch)
			vlFunction.m_lpDispatch = NULL;
		if(vlFunctions.m_lpDispatch) 
			vlFunctions.m_lpDispatch = NULL;
		if(vlActiveDocument.m_lpDispatch) 
			vlActiveDocument.m_lpDispatch = NULL;
		if(VLISP.m_lpDispatch)
			VLISP.m_lpDispatch = NULL;
		if(ActiveDoc.m_lpDispatch) 
			ActiveDoc.m_lpDispatch = NULL;
		if(DBX.m_lpDispatch) 
			DBX.m_lpDispatch = NULL;
		if(App.m_lpDispatch)
			App.m_lpDispatch = NULL;
	}
} WNDINFO, *LPWNDINFO;
typedef std::map<DWORD,WNDINFO> MapProcessIDToWndinfo;











