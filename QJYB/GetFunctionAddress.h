#pragma once
typedef map<string,INT_PTR> FUNCTION_ADDRESS;
int getFuncAddr(LPCTSTR szFileName,FUNCTION_ADDRESS &funs);
FARPROC LoadFuncBase(LPCTSTR fileName,LPCSTR lpProcName,HMODULE & hDLL);
typedef PVOID (__cdecl *AcApGetDatabase)(CView *);
typedef CView* (__cdecl *acedGetAcadDwgView)(void);
typedef void* (__cdecl *acDocManagerPtr)(void);
