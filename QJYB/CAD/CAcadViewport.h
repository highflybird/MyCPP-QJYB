// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadViewport wrapper class

class CAcadViewport : public COleDispatchDriver
{
public:
	CAcadViewport(){} // Calls COleDispatchDriver default constructor
	CAcadViewport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadViewport(const CAcadViewport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadViewport methods
public:
	CString get_Handle()
	{
		CString result;
		InvokeHelper(0x400, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ObjectName()
	{
		CString result;
		InvokeHelper(0x401, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void GetXData(LPCTSTR AppName, VARIANT * XDataType, VARIANT * XDataValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x402, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AppName, XDataType, XDataValue);
	}
	void SetXData(VARIANT& XDataType, VARIANT& XDataValue)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x403, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &XDataType, &XDataValue);
	}
	void Delete()
	{
		InvokeHelper(0x404, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_ObjectID()
	{
		long result;
		InvokeHelper(0x405, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x406, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Database()
	{
		LPDISPATCH result;
		InvokeHelper(0x407, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_HasExtensionDictionary()
	{
		BOOL result;
		InvokeHelper(0x408, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetExtensionDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0x409, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_OwnerID()
	{
		long result;
		InvokeHelper(0x40a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Document()
	{
		LPDISPATCH result;
		InvokeHelper(0x40b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Erase()
	{
		InvokeHelper(0x475, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	VARIANT get_Center()
	{
		VARIANT result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Center(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	double get_Height()
	{
		double result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Height(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Width()
	{
		double result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_Width(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Target()
	{
		VARIANT result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Target(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	VARIANT get_Direction()
	{
		VARIANT result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Direction(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_GridOn()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_GridOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_OrthoOn()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_OrthoOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_SnapBasePoint()
	{
		VARIANT result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_SnapBasePoint(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	BOOL get_SnapOn()
	{
		BOOL result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_SnapOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_SnapRotationAngle()
	{
		double result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_SnapRotationAngle(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UCSIconOn()
	{
		BOOL result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UCSIconOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UCSIconAtOrigin()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UCSIconAtOrigin(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_LowerLeftCorner()
	{
		VARIANT result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT get_UpperRightCorner()
	{
		VARIANT result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void Split(long NumWins)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms, NumWins);
	}
	void GetGridSpacing(double * XSpacing, double * YSpacing)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, XSpacing, YSpacing);
	}
	void SetGridSpacing(double XSpacing, double YSpacing)
	{
		static BYTE parms[] = VTS_R8 VTS_R8 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms, XSpacing, YSpacing);
	}
	void GetSnapSpacing(double * XSpacing, double * YSpacing)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms, XSpacing, YSpacing);
	}
	void SetSnapSpacing(double XSpacing, double YSpacing)
	{
		static BYTE parms[] = VTS_R8 VTS_R8 ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms, XSpacing, YSpacing);
	}
	void SetView(LPDISPATCH View)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms, View);
	}
	long get_ArcSmoothness()
	{
		long result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ArcSmoothness(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IAcadViewport properties
public:

};
