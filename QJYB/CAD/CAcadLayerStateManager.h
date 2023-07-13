// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadLayerStateManager wrapper class

class CAcadLayerStateManager : public COleDispatchDriver
{
public:
	CAcadLayerStateManager(){} // Calls COleDispatchDriver default constructor
	CAcadLayerStateManager(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadLayerStateManager(const CAcadLayerStateManager& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadLayerStateManager methods
public:
	void SetDatabase(LPDISPATCH iHostDb)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020000, DISPATCH_METHOD, VT_EMPTY, NULL, parms, iHostDb);
	}
	void put_Mask(LPCTSTR bsName, long newValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, bsName, newValue);
	}
	long get_Mask(LPCTSTR bsName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, bsName);
		return result;
	}
	void Save(LPCTSTR bsName, long eMask)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bsName, eMask);
	}
	void Restore(LPCTSTR bsName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bsName);
	}
	void Delete(LPCTSTR bsName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bsName);
	}
	void Rename(LPCTSTR bsName, LPCTSTR bsNewName)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bsName, bsNewName);
	}
	void Import(LPCTSTR bsFilename)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bsFilename);
	}
	void Export(LPCTSTR bsName, LPCTSTR bsFilename)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bsName, bsFilename);
	}

	// IAcadLayerStateManager properties
public:

};
