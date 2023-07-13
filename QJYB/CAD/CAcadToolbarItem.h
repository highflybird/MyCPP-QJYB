// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadToolbarItem wrapper class

class CAcadToolbarItem : public COleDispatchDriver
{
public:
	CAcadToolbarItem(){} // Calls COleDispatchDriver default constructor
	CAcadToolbarItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadToolbarItem(const CAcadToolbarItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadToolbarItem methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_TagString()
	{
		CString result;
		InvokeHelper(0x60020004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_TagString(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Type()
	{
		long result;
		InvokeHelper(0x60020006, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Flyout()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_Macro()
	{
		CString result;
		InvokeHelper(0x60020008, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Macro(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020008, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Index()
	{
		long result;
		InvokeHelper(0x6002000a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_HelpString()
	{
		CString result;
		InvokeHelper(0x6002000b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_HelpString(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6002000b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void GetBitmaps(BSTR * SmallIconName, BSTR * LargeIconName)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x6002000d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SmallIconName, LargeIconName);
	}
	void SetBitmaps(LPCTSTR SmallIconName, LPCTSTR LargeIconName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6002000e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SmallIconName, LargeIconName);
	}
	void AttachToolbarToFlyout(LPCTSTR MenuGroupName, LPCTSTR ToolbarName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6002000f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, MenuGroupName, ToolbarName);
	}
	void Delete()
	{
		InvokeHelper(0x60020010, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IAcadToolbarItem properties
public:

};
