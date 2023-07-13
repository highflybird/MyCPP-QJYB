// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// 从 Windows 头中排除极少使用的资料
#endif

// 如果您必须使用下列所指定的平台之前的平台，则修改下面的定义。
// 有关不同平台的相应值的最新信息，请参考 MSDN。
#ifndef WINVER				// 允许使用特定于 Windows XP 或更高版本的功能。
#define WINVER 0x0501		// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT		// 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501	// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif						

#ifndef _WIN32_WINDOWS		// 允许使用特定于 Windows 98 或更高版本的功能。
#define _WIN32_WINDOWS 0x0410 // 将它更改为适合 Windows Me 或更高版本的相应值。
#endif

#ifndef _WIN32_IE			// 允许使用特定于 IE 6.0 或更高版本的功能。
#define _WIN32_IE 0x0600	// 将此值更改为相应的值，以适用于 IE 的其他版本。值。
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC 对 Windows 公共控件的支持
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
#include <afxmt.h>	//同步操作时需要包含的头文件

#pragma comment(lib, "version.lib")
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "mscoree.lib")
#pragma comment(lib, "Dbghelp.lib")

#pragma warning(disable: 4995)
#pragma warning(disable: 4996)
#pragma warning(disable: 4267)  //possible loss of data 警告
#pragma warning(disable: 4312)  //conversion from 'LONG' to 'HWND' of greater size 警告
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

//定义一个进程ID和窗口句柄的结构体
typedef class tagWNDINFO
{
public:
	DWORD				dwProcessId;		//进程号
	bool				is64bit;			//是否为64位的CAD
	bool				isRemoved;			//是否已经消除了教育版戳记
	bool				isAttached;			//是否和CAD建立了连接
	bool                isLinkedWithLisp;	//是否和LISP建立了连接
	HWND				hWnd;				//CAD的窗口句柄
	HMODULE				hMod;				//acad.exe模块加载基址
	HMODULE				hAcDb;				//acdbXX.dll模块加载基址
	HMODULE				hAcCore;			//accore.dll模块加载基址		
	CString				strVersion;			//AutoCAD版本号
	CString				strWindowText;		//CAD窗口标题
	CString				strClassName;		//CAD类名
	CString				strAppPath;			//acad.exe程序全路径
	CString				strAcDbPath;		//acdbXX.dll全路径
	CString				strAcCorePath;		//accore.dll全路径

	CAcadApplication	App;				//acad对象
	CAcadDocument		ActiveDoc;			//当前文档
	CAxDbDocument       DBX;
	CDVlApplication		VLISP;				//VLISP程序对象
	CDVlDocument		vlActiveDocument;	//VLISP的当前文档
	CDVlFunctions		vlFunctions;		//VLISP的全部函数
	CDVlFunction		vlFunction;			//VLISP函数对象
 
public:
	//构造函数
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
	//析构函数
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











