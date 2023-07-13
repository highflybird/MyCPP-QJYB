// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadPlot wrapper class

class CAcadPlot : public COleDispatchDriver
{
public:
	CAcadPlot(){} // Calls COleDispatchDriver default constructor
	CAcadPlot(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadPlot(const CAcadPlot& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadPlot methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_QuietErrorMode()
	{
		BOOL result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_QuietErrorMode(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_NumberOfCopies()
	{
		long result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_NumberOfCopies(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_BatchPlotProgress()
	{
		BOOL result;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_BatchPlotProgress(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void DisplayPlotPreview(long Preview)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Preview);
	}
	BOOL PlotToFile(LPCTSTR plotFile, VARIANT& plotConfig)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, plotFile, &plotConfig);
		return result;
	}
	BOOL PlotToDevice(VARIANT& plotConfig)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &plotConfig);
		return result;
	}
	void SetLayoutsToPlot(VARIANT& layoutList)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &layoutList);
	}
	void StartBatchMode(long entryCount)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, entryCount);
	}

	// IAcadPlot properties
public:

};
