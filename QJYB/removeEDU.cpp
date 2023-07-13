#include "stdafx.h"
#include "GetProcess.h"
#include "GetFunctionAddress.h"
#include "RemoveEDU.h"

byte OffsetAddress32[6][6]={
	{0xa4,0x06,0xa4,0x06,0xa4,0x06},//R15
	{0xd4,0x06,0xd4,0x06,0xd4,0x06},//R16
	{0xdc,0x07,0x24,0x08,0x34,0x08},//R17
	{0x6c,0x08,0x74,0x08,0x7c,0x08},//R18
	{0x84,0x08,0x84,0x08,0x84,0x08},//R19
	{0x84,0x08,0x84,0x08,0x84,0x08},//R23
};
byte OffsetAddress64[4][6]={
	{0x18,0x0b,0x18,0x0b,0x18,0x0b},//R17
	{0x80,0x0b,0x88,0x0b,0x90,0x0b},//R18
	{0xa8,0x0b,0xb0,0x0b,0xb8,0x0b},//R19
	{0xa0,0x0b,0xa0,0x0b,0xa0,0x0b},//R23
};

int RemoveEducationStamp(WNDINFO & wi)
{
	if (wi.ActiveDoc==NULL)
		return FALSE;
	int ret = FALSE;
    CAcadUtility uti=wi.ActiveDoc.get_Utility();
	//��ȡisEMR������RVA��ַ
	INT_PTR offsetAddr = 0;
	LPCSTR funcName = wi.is64bit ? "?isEMR@AcDbDatabase@@QEBA_NXZ" : "?isEMR@AcDbDatabase@@QBE_NXZ";

	HMODULE hDLL = LoadLibraryEx(wi.strAcDbPath,0,DONT_RESOLVE_DLL_REFERENCES);// 
	LPVOID pIsEMR = GetProcAddress(hDLL,funcName);
	FreeLibrary(hDLL);
	if (pIsEMR == NULL)
	{
		pIsEMR = LoadFuncBase(wi.strAcDbPath,funcName,hDLL);
	}
	
	if (pIsEMR == NULL)
	{
		FUNCTION_ADDRESS funcSet;
		ret = getFuncAddr(wi.strAcDbPath,funcSet);
		FUNCTION_ADDRESS::iterator itr = funcSet.find(funcName); 
		if (itr == funcSet.end())
		{
			uti.Prompt(_T("�Ҳ�����������غ�����������Ҫ�Թ���Ա������д˳��򣬻���CAD�汾��2015-2018.\n"));
			return FALSE;
		}
		offsetAddr = itr->second;
		pIsEMR = LPVOID((INT_PTR)wi.hAcDb + offsetAddr); //�������ݿ�
	}
	else
	{
		offsetAddr = (INT_PTR)pIsEMR - (INT_PTR)hDLL;
		pIsEMR = LPVOID((INT_PTR)wi.hAcDb + offsetAddr); //�������ݿ�		
	}

	//��д�ķ�ʽ��CAD����
	//HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, wi.dwProcessId); //Ȩ��Ҫ��̫�ߣ�������ĳЩ���������в���
	HANDLE hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_QUERY_INFORMATION | PROCESS_VM_WRITE, FALSE, wi.dwProcessId);
	if (hProcess == NULL)
	{
		uti.Prompt(_T("�޷���CAD����д��!\n"));
		return FALSE;
	}

	const DWORD bWritten = 128;
	byte pEAX = 0;
	SIZE_T dwNumberOfBytes = 0;

	CString strTemp = wi.strVersion.Mid(1,2);
	int nMajorVersion = _ttoi(strTemp.GetBuffer());
	if (nMajorVersion>22) 
		nMajorVersion-=3;
	strTemp = wi.strVersion.Mid(4,1);
	int nMinorVersion = _ttoi(strTemp.GetBuffer());
   
	if (wi.is64bit)
	{
		byte AsmCode[15] = {0x48,0x8B,0x49,0x08,0x33,0xC0,0x89,0x81,0x00,0x00,0x00,0x00,0x3C,0x00,0xC3};
		nMajorVersion = nMajorVersion-17;
		AsmCode[8]=OffsetAddress64[nMajorVersion][2*nMinorVersion];
		AsmCode[9]=OffsetAddress64[nMajorVersion][2*nMinorVersion+1];
		ret = WriteProcessMemory(hProcess,pIsEMR,AsmCode,sizeof(AsmCode),&dwNumberOfBytes);
	}
	else
	{
		byte AsmCode[14] = {0x8B,0x49,0x04,0x33,0xC0,0x89,0x81,0x00,0x00,0x00,0x00,0x3C,0x00,0xC3};
		nMajorVersion = nMajorVersion-15;
		AsmCode[7]=OffsetAddress32[nMajorVersion][2*nMinorVersion];
		AsmCode[8]=OffsetAddress32[nMajorVersion][2*nMinorVersion+1];
		ret = WriteProcessMemory(hProcess,pIsEMR,AsmCode,sizeof(AsmCode),&dwNumberOfBytes);
	}

	if (!ret)
	{
		uti.Prompt(_T("�޸��ڴ�ģʽʧ��!\n"));
	}
	else
	{
		wi.isRemoved = true;
	}

	CloseHandle(hProcess);
	return ret;
}