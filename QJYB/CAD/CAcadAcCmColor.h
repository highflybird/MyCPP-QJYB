// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "axdb16enu.tlb" no_namespace
// CAcadAcCmColor wrapper class

class CAcadAcCmColor : public COleDispatchDriver
{
public:
	CAcadAcCmColor(){} // Calls COleDispatchDriver default constructor
	CAcadAcCmColor(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadAcCmColor(const CAcadAcCmColor& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadAcCmColor methods
public:
	void put_EntityColor(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_EntityColor()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_ColorName()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_BookName()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void SetNames(LPCTSTR ColorName, LPCTSTR BookName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ColorName, BookName);
	}
	void Delete()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_Red()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Blue()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Green()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void SetRGB(long Red, long Green, long Blue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Red, Green, Blue);
	}
	void put_ColorMethod(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ColorMethod()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_ColorIndex()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ColorIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void SetColorBookColor(LPCTSTR BookName, LPCTSTR ColorName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, BookName, ColorName);
	}

	// IAcadAcCmColor properties
public:

};
