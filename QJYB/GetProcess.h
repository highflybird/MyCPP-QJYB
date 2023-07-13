#pragma once
//typedef int (_cdecl *acedEvaluateLisp)(wchar_t const *,struct resbuf * &);
//typedef int (_cdecl *acutNewBuffer)(TCHAR * &,unsigned int);
//typedef resbuf* (*acutNewRb)(unsigned int);

void SetMapping();
void doPathMapping(WCHAR* path);

HANDLE GetProcessHandle(int nID);
HANDLE GetProcessHandle(LPCTSTR pName);
HWND GetWindowHandleByPID(DWORD dwProcessID);

BOOL CALLBACK EnumWindowsProc(HWND hWnd,LPARAM lParam);
int FindProcessByName(LPCTSTR proc_name,MapProcessIDToWndinfo & WndSet);

CString GetAppVersion(LPCTSTR fileName);
CString GetProcessFullName(DWORD idProcess );	//获取进程路径

HMODULE fnGetProcessBase(DWORD PID);
DWORD GetLastErrorBox(HWND hWnd, LPCTSTR lpTitle,CString & messgetOut) ;


