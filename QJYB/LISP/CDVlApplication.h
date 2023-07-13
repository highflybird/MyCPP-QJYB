// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "vl16.tlb" no_namespace
// CDVlApplication wrapper class

class CDVlApplication : public COleDispatchDriver
{
public:
	CDVlApplication(){} // Calls COleDispatchDriver default constructor
	CDVlApplication(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDVlApplication(const CDVlApplication& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// DVlApplication methods
public:
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Documents()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_ActiveDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// DVlApplication properties
public:

};
