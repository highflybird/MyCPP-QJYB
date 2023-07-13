// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadSpline wrapper class

class CAcadSpline : public COleDispatchDriver
{
public:
	CAcadSpline(){} // Calls COleDispatchDriver default constructor
	CAcadSpline(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadSpline(const CAcadSpline& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadSpline methods
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
	long get_NumberOfControlPoints()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_ControlPoints()
	{
		VARIANT result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_ControlPoints(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	long get_NumberOfFitPoints()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_FitPoints()
	{
		VARIANT result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_FitPoints(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	long get_Degree()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL get_Closed()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsPlanar()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsRational()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsPeriodic()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	VARIANT get_StartTangent()
	{
		VARIANT result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_StartTangent(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	VARIANT get_EndTangent()
	{
		VARIANT result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_EndTangent(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	double get_FitTolerance()
	{
		double result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_FitTolerance(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_Area()
	{
		double result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void SetControlPoint(long Index, VARIANT& controlPoint)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index, &controlPoint);
	}
	VARIANT GetControlPoint(long Index)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Index);
		return result;
	}
	void SetFitPoint(long Index, VARIANT& fitPoint)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index, &fitPoint);
	}
	VARIANT GetFitPoint(long Index)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Index);
		return result;
	}
	void SetWeight(long Index, double weight)
	{
		static BYTE parms[] = VTS_I4 VTS_R8 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index, weight);
	}
	double GetWeight(long Index)
	{
		double result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Index);
		return result;
	}
	void AddFitPoint(long Index, VARIANT& fitPoint)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index, &fitPoint);
	}
	void DeleteFitPoint(long Index)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Index);
	}
	void ElevateOrder(long Order)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Order);
	}
	VARIANT Offset(double Distance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Distance);
		return result;
	}
	void PurgeFitData()
	{
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Reverse()
	{
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	VARIANT get_Knots()
	{
		VARIANT result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Knots(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	VARIANT get_Weights()
	{
		VARIANT result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Weights(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}

	// IAcadSpline properties
public:

};
