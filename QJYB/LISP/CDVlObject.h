// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "vl16.tlb" no_namespace
// CDVlObject wrapper class

class CDVlObject : public COleDispatchDriver
{
public:
	CDVlObject(){} // Calls COleDispatchDriver default constructor
	CDVlObject(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDVlObject(const CDVlObject& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// DVlObject methods
public:
	unsigned long _getAcDocId()
	{
		unsigned long result;
		InvokeHelper(0x1f5, DISPATCH_METHOD, VT_UI4, (void*)&result, NULL);
		return result;
	}

	// DVlObject properties
public:
	VARIANT GetValue()
	{
		VARIANT result;
		GetProperty(0x0, VT_VARIANT, (void*)&result);
		return result;
	}
	void SetValue(VARIANT &propVal)
	{
		SetProperty(0x0, VT_VARIANT, &propVal);
	}
	CString GetType()
	{
		CString result;
		GetProperty(0x1, VT_BSTR, (void*)&result);
		return result;
	}
	void SetType(CString propVal)
	{
		SetProperty(0x1, VT_BSTR, propVal);
	}

};
