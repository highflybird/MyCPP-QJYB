// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CDAcadDocumentEvents wrapper class

class CDAcadDocumentEvents : public COleDispatchDriver
{
public:
	CDAcadDocumentEvents(){} // Calls COleDispatchDriver default constructor
	CDAcadDocumentEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDAcadDocumentEvents(const CDAcadDocumentEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _DAcadDocumentEvents methods
public:
	STDMETHOD(BeginSave)(LPCTSTR FileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName);
		return result;
	}
	STDMETHOD(EndSave)(LPCTSTR FileName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FileName);
		return result;
	}
	STDMETHOD(BeginCommand)(LPCTSTR CommandName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, CommandName);
		return result;
	}
	STDMETHOD(EndCommand)(LPCTSTR CommandName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, CommandName);
		return result;
	}
	STDMETHOD(BeginLisp)(LPCTSTR FirstLine)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, FirstLine);
		return result;
	}
	STDMETHOD(EndLisp)()
	{
		HRESULT result;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(LispCancelled)()
	{
		HRESULT result;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(SelectionChanged)()
	{
		HRESULT result;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(Activate)()
	{
		HRESULT result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(Deactivate)()
	{
		HRESULT result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}
	STDMETHOD(BeginRightClick)(VARIANT& PickPoint)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, &PickPoint);
		return result;
	}
	STDMETHOD(BeginShortcutMenuDefault)(LPDISPATCH * ShortcutMenu)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ShortcutMenu);
		return result;
	}
	STDMETHOD(BeginShortcutMenuEdit)(LPDISPATCH * ShortcutMenu, LPDISPATCH * SelectionSet)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PDISPATCH ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ShortcutMenu, SelectionSet);
		return result;
	}
	STDMETHOD(BeginShortcutMenuCommand)(LPDISPATCH * ShortcutMenu, LPCTSTR Command)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_BSTR ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ShortcutMenu, Command);
		return result;
	}
	STDMETHOD(BeginShortcutMenuGrip)(LPDISPATCH * ShortcutMenu)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ShortcutMenu);
		return result;
	}
	STDMETHOD(BeginShortcutMenuOsnap)(LPDISPATCH * ShortcutMenu)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ShortcutMenu);
		return result;
	}
	STDMETHOD(EndShortcutMenu)(LPDISPATCH * ShortcutMenu)
	{
		HRESULT result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ShortcutMenu);
		return result;
	}
	STDMETHOD(BeginDoubleClick)(VARIANT& PickPoint)
	{
		HRESULT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, &PickPoint);
		return result;
	}
	STDMETHOD(ObjectAdded)(LPDISPATCH Object)
	{
		HRESULT result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, Object);
		return result;
	}
	STDMETHOD(ObjectErased)(long ObjectID)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, ObjectID);
		return result;
	}
	STDMETHOD(ObjectModified)(LPDISPATCH Object)
	{
		HRESULT result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, Object);
		return result;
	}
	STDMETHOD(BeginPlot)(LPCTSTR DrawingName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, DrawingName);
		return result;
	}
	STDMETHOD(EndPlot)(LPCTSTR DrawingName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, DrawingName);
		return result;
	}
	STDMETHOD(WindowMovedOrResized)(long HWNDFrame, BOOL bMoved)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, HWNDFrame, bMoved);
		return result;
	}
	STDMETHOD(LayoutSwitched)(LPCTSTR LayoutName)
	{
		HRESULT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, LayoutName);
		return result;
	}
	STDMETHOD(WindowChanged)(long WindowState)
	{
		HRESULT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_HRESULT, (void*)&result, parms, WindowState);
		return result;
	}
	STDMETHOD(BeginClose)()
	{
		HRESULT result;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_HRESULT, (void*)&result, NULL);
		return result;
	}

	// _DAcadDocumentEvents properties
public:

};
