// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadLeader wrapper class

class CAcadLeader : public COleDispatchDriver
{
public:
	CAcadLeader(){} // Calls COleDispatchDriver default constructor
	CAcadLeader(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadLeader(const CAcadLeader& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadLeader methods
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
	long get_Color()
	{
		long result;
		InvokeHelper(0x500, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Color(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x500, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Layer()
	{
		CString result;
		InvokeHelper(0x501, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Layer(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x501, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Linetype()
	{
		CString result;
		InvokeHelper(0x502, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Linetype(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x502, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_LinetypeScale()
	{
		double result;
		InvokeHelper(0x503, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_LinetypeScale(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x503, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Visible()
	{
		BOOL result;
		InvokeHelper(0x504, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Visible(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x504, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT ArrayPolar(long NumberOfObjects, double AngleToFill, VARIANT& CenterPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_R8 VTS_VARIANT ;
		InvokeHelper(0x505, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, NumberOfObjects, AngleToFill, &CenterPoint);
		return result;
	}
	VARIANT ArrayRectangular(long NumberOfRows, long NumberOfColumns, long NumberOfLevels, double DistBetweenRows, double DistBetweenCols, double DistBetweenLevels)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_R8 VTS_R8 VTS_R8 ;
		InvokeHelper(0x506, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, NumberOfRows, NumberOfColumns, NumberOfLevels, DistBetweenRows, DistBetweenCols, DistBetweenLevels);
		return result;
	}
	void Highlight(BOOL HighlightFlag)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x507, DISPATCH_METHOD, VT_EMPTY, NULL, parms, HighlightFlag);
	}
	LPDISPATCH Copy()
	{
		LPDISPATCH result;
		InvokeHelper(0x508, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Move(VARIANT& FromPoint, VARIANT& ToPoint)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x509, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &FromPoint, &ToPoint);
	}
	void Rotate(VARIANT& BasePoint, double RotationAngle)
	{
		static BYTE parms[] = VTS_VARIANT VTS_R8 ;
		InvokeHelper(0x50a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &BasePoint, RotationAngle);
	}
	void Rotate3D(VARIANT& Point1, VARIANT& Point2, double RotationAngle)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_R8 ;
		InvokeHelper(0x50b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Point1, &Point2, RotationAngle);
	}
	LPDISPATCH Mirror(VARIANT& Point1, VARIANT& Point2)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x50c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Point1, &Point2);
		return result;
	}
	LPDISPATCH Mirror3D(VARIANT& Point1, VARIANT& Point2, VARIANT& point3)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x50d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Point1, &Point2, &point3);
		return result;
	}
	void ScaleEntity(VARIANT& BasePoint, double ScaleFactor)
	{
		static BYTE parms[] = VTS_VARIANT VTS_R8 ;
		InvokeHelper(0x50e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &BasePoint, ScaleFactor);
	}
	void TransformBy(VARIANT& TransformationMatrix)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x50f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &TransformationMatrix);
	}
	void Update()
	{
		InvokeHelper(0x510, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GetBoundingBox(VARIANT * MinPoint, VARIANT * MaxPoint)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x511, DISPATCH_METHOD, VT_EMPTY, NULL, parms, MinPoint, MaxPoint);
	}
	VARIANT IntersectWith(LPDISPATCH IntersectObject, long option)
	{
		VARIANT result;
		static BYTE parms[] = VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0x512, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, IntersectObject, option);
		return result;
	}
	CString get_PlotStyleName()
	{
		CString result;
		InvokeHelper(0x513, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_PlotStyleName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x513, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Lineweight()
	{
		long result;
		InvokeHelper(0x514, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Lineweight(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x514, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Hyperlinks()
	{
		LPDISPATCH result;
		InvokeHelper(0x515, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_EntityName()
	{
		CString result;
		InvokeHelper(0x575, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_EntityType()
	{
		long result;
		InvokeHelper(0x576, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_Coordinates()
	{
		VARIANT result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Coordinates(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x40, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	VARIANT get_Normal()
	{
		VARIANT result;
		InvokeHelper(0x601, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	CString get_StyleName()
	{
		CString result;
		InvokeHelper(0x606, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_StyleName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x606, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Type()
	{
		long result;
		InvokeHelper(0x41, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Type(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x41, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void Evaluate()
	{
		InvokeHelper(0x42, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	VARIANT get_Coordinate(long Index)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms, Index);
		return result;
	}
	void put_Coordinate(long Index, VARIANT& newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x43, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, &newValue);
	}
	LPDISPATCH get_Annotation()
	{
		LPDISPATCH result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_Annotation(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x44, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_ArrowheadSize()
	{
		double result;
		InvokeHelper(0x607, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_ArrowheadSize(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x607, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ArrowheadType()
	{
		long result;
		InvokeHelper(0x45, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ArrowheadType(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x45, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_DimensionLineColor()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DimensionLineColor(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_DimensionLineWeight()
	{
		long result;
		InvokeHelper(0x60e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DimensionLineWeight(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_ScaleFactor()
	{
		double result;
		InvokeHelper(0x611, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_ScaleFactor(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x611, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_VerticalTextPosition()
	{
		long result;
		InvokeHelper(0x612, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_VerticalTextPosition(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x612, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_TextGap()
	{
		double result;
		InvokeHelper(0x60d, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_TextGap(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x60d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ArrowheadBlock()
	{
		CString result;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ArrowheadBlock(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x46, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IAcadLeader properties
public:

};
