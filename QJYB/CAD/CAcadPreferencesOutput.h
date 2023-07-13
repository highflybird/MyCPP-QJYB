// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadPreferencesOutput wrapper class

class CAcadPreferencesOutput : public COleDispatchDriver
{
public:
	CAcadPreferencesOutput(){} // Calls COleDispatchDriver default constructor
	CAcadPreferencesOutput(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadPreferencesOutput(const CAcadPreferencesOutput& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadPreferencesOutput methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_DefaultOutputDevice(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_DefaultOutputDevice()
	{
		CString result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_PrinterSpoolAlert(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PrinterSpoolAlert()
	{
		long result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PrinterPaperSizeAlert(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_PrinterPaperSizeAlert()
	{
		BOOL result;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_PlotLegacy(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_PlotLegacy()
	{
		BOOL result;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_OLEQuality(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020009, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_OLEQuality()
	{
		long result;
		InvokeHelper(0x60020009, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_UseLastPlotSettings(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x6002000b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UseLastPlotSettings()
	{
		BOOL result;
		InvokeHelper(0x6002000b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_PlotPolicy(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6002000d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PlotPolicy()
	{
		long result;
		InvokeHelper(0x6002000d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DefaultPlotStyleTable(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6002000f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_DefaultPlotStyleTable()
	{
		CString result;
		InvokeHelper(0x6002000f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_DefaultPlotStyleForObjects(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020011, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_DefaultPlotStyleForObjects()
	{
		CString result;
		InvokeHelper(0x60020011, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_DefaultPlotStyleForLayer(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020013, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_DefaultPlotStyleForLayer()
	{
		CString result;
		InvokeHelper(0x60020013, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// IAcadPreferencesOutput properties
public:

};
