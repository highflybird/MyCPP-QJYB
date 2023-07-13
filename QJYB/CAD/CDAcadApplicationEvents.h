// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CDAcadApplicationEvents wrapper class

class CDAcadApplicationEvents : public COleDispatchDriver
{
public:
	CDAcadApplicationEvents(){} // Calls COleDispatchDriver default constructor
	CDAcadApplicationEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDAcadApplicationEvents(const CDAcadApplicationEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _DAcadApplicationEvents methods
public:
	STDMETHOD(SysVarChanged)(LPCTSTR SysvarName, VARIANT& newVal)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, SysvarName, &newVal);
		return result;
	}
	STDMETHOD(NewDrawing)()
	{
		HRESULT result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(AppActivate)()
	{
		HRESULT result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(AppDeactivate)()
	{
		HRESULT result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(WindowMovedOrResized)(long HWNDFrame, BOOL bMoved)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, HWNDFrame, bMoved);
		return result;
	}
	STDMETHOD(BeginModal)()
	{
		HRESULT result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(EndModal)()
	{
		HRESULT result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(BeginQuit)(BOOL * Cancel)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, Cancel);
		return result;
	}
	STDMETHOD(BeginFileDrop)(LPCTSTR FileName, BOOL * Cancel)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR VTS_PBOOL ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName, Cancel);
		return result;
	}
	STDMETHOD(ARXLoaded)(LPCTSTR AppName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, AppName);
		return result;
	}
	STDMETHOD(ARXUnloaded)(LPCTSTR AppName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, AppName);
		return result;
	}
	STDMETHOD(BeginPlot)(LPCTSTR DrawingName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, DrawingName);
		return result;
	}
	STDMETHOD(EndPlot)(LPCTSTR DrawingName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, DrawingName);
		return result;
	}
	STDMETHOD(BeginSave)(LPCTSTR FileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName);
		return result;
	}
	STDMETHOD(EndSave)(LPCTSTR FileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName);
		return result;
	}
	STDMETHOD(BeginOpen)(BSTR * FileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName);
		return result;
	}
	STDMETHOD(EndOpen)(LPCTSTR FileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName);
		return result;
	}
	STDMETHOD(BeginCommand)(LPCTSTR CommandName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, CommandName);
		return result;
	}
	STDMETHOD(EndCommand)(LPCTSTR CommandName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, CommandName);
		return result;
	}
	STDMETHOD(BeginLisp)(LPCTSTR FirstLine)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FirstLine);
		return result;
	}
	STDMETHOD(EndLisp)()
	{
		HRESULT result;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(LispCancelled)()
	{
		HRESULT result;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(WindowChanged)(long WindowState)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, WindowState);
		return result;
	}

	// _DAcadApplicationEvents properties
public:

};
