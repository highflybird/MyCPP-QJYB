// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadPreferencesProfiles wrapper class

class CAcadPreferencesProfiles : public COleDispatchDriver
{
public:
	CAcadPreferencesProfiles(){} // Calls COleDispatchDriver default constructor
	CAcadPreferencesProfiles(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadPreferencesProfiles(const CAcadPreferencesProfiles& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadPreferencesProfiles methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_ActiveProfile(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ActiveProfile()
	{
		CString result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void ImportProfile(LPCTSTR ProfileName, LPCTSTR RegFile, BOOL IncludePathInfo)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ProfileName, RegFile, IncludePathInfo);
	}
	void ExportProfile(LPCTSTR ProfileName, LPCTSTR RegFile)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ProfileName, RegFile);
	}
	void DeleteProfile(LPCTSTR ProfileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ProfileName);
	}
	void ResetProfile(LPCTSTR Profile)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Profile);
	}
	void RenameProfile(LPCTSTR origProfileName, LPCTSTR newProfileName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms, origProfileName, newProfileName);
	}
	void CopyProfile(LPCTSTR oldProfileName, LPCTSTR newProfileName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, NULL, parms, oldProfileName, newProfileName);
	}
	void GetAllProfileNames(VARIANT * pNames)
	{
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pNames);
	}

	// IAcadPreferencesProfiles properties
public:

};
