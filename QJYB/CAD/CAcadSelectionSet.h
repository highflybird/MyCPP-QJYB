// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadSelectionSet wrapper class

class CAcadSelectionSet : public COleDispatchDriver
{
public:
	CAcadSelectionSet(){} // Calls COleDispatchDriver default constructor
	CAcadSelectionSet(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadSelectionSet(const CAcadSelectionSet& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadSelectionSet methods
public:
	LPDISPATCH Item(VARIANT& Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void Highlight(BOOL bFlag)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bFlag);
	}
	void Erase()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Update()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void AddItems(VARIANT& pSelSet)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &pSelSet);
	}
	void RemoveItems(VARIANT& Objects)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Objects);
	}
	void Clear()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Select(long Mode, VARIANT& Point1, VARIANT& Point2, VARIANT& FilterType, VARIANT& FilterData)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Mode, &Point1, &Point2, &FilterType, &FilterData);
	}
	void SelectAtPoint(VARIANT& Point, VARIANT& FilterType, VARIANT& FilterData)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Point, &FilterType, &FilterData);
	}
	void SelectByPolygon(long Mode, VARIANT& PointsList, VARIANT& FilterType, VARIANT& FilterData)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Mode, &PointsList, &FilterType, &FilterData);
	}
	void SelectOnScreen(VARIANT& FilterType, VARIANT& FilterData)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &FilterType, &FilterData);
	}
	void Delete()
	{
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IAcadSelectionSet properties
public:

};
