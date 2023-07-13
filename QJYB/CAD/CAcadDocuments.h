// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "acad.tlb" no_namespace
// CAcadDocuments wrapper class

class CAcadDocuments : public COleDispatchDriver
{
public:
	CAcadDocuments(){} // Calls COleDispatchDriver default constructor
	CAcadDocuments(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadDocuments(const CAcadDocuments& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadDocuments methods
public:
	LPDISPATCH Item(VARIANT& Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Add(VARIANT& TemplateName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &TemplateName);
		return result;
	}
	LPDISPATCH Open(LPCTSTR Name, VARIANT& ReadOnly)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, &ReadOnly);
		return result;
	}
	void Close()
	{
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IAcadDocuments properties
public:

};
