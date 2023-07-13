// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "vl16.tlb" no_namespace
// CDVlDocument wrapper class

class CDVlDocument : public COleDispatchDriver
{
public:
	CDVlDocument(){} // Calls COleDispatchDriver default constructor
	CDVlDocument(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDVlDocument(const CDVlDocument& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// DVlDocument methods
public:
	LPDISPATCH get_Functions()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// DVlDocument properties
public:
	CString GetTitle()
	{
		CString result;
		GetProperty(0x0, VT_BSTR, (void*)&result);
		return result;
	}
	void SetTitle(CString propVal)
	{
		SetProperty(0x0, VT_BSTR, propVal);
	}

};
