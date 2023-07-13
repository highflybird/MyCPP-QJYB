// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "vl16.tlb" no_namespace
// CDVlFunctions wrapper class

class CDVlFunctions : public COleDispatchDriver
{
public:
	CDVlFunctions(){} // Calls COleDispatchDriver default constructor
	CDVlFunctions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDVlFunctions(const CDVlFunctions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:
   
	void Release ()
	{
		ReleaseDispatch();
	}

	// DVlFunctions methods
public:
	LPDISPATCH get_Item(LPCTSTR Name)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Name);
		return result;
	}

	// DVlFunctions properties
public:

};
