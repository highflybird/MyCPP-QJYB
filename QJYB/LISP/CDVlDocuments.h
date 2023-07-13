// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "vl16.tlb" no_namespace
// CDVlDocuments wrapper class

class CDVlDocuments : public COleDispatchDriver
{
public:
	CDVlDocuments(){} // Calls COleDispatchDriver default constructor
	CDVlDocuments(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDVlDocuments(const CDVlDocuments& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// DVlDocuments methods
public:
	LPDISPATCH get_Item(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	// DVlDocuments properties
public:

};
