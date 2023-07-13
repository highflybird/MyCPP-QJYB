// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "acad.tlb" no_namespace
// CAcadUtility wrapper class

class CAcadUtility : public COleDispatchDriver
{
public:
	CAcadUtility(){} // Calls COleDispatchDriver default constructor
	CAcadUtility(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadUtility(const CAcadUtility& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadUtility methods
public:
	double AngleToReal(LPCTSTR Angle, long Unit)
	{
		double result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x60020000, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Angle, Unit);
		return result;
	}
	CString AngleToString(double Angle, long Unit, long precision)
	{
		CString result;
		static BYTE parms[] = VTS_R8 VTS_I4 VTS_I4 ;
		InvokeHelper(0x60020001, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Angle, Unit, precision);
		return result;
	}
	double DistanceToReal(LPCTSTR Distance, long Unit)
	{
		double result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x60020002, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Distance, Unit);
		return result;
	}
	CString RealToString(double Value, long Unit, long precision)
	{
		CString result;
		static BYTE parms[] = VTS_R8 VTS_I4 VTS_I4 ;
		InvokeHelper(0x60020003, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Value, Unit, precision);
		return result;
	}
	VARIANT TranslateCoordinates(VARIANT& Point, long FromCoordSystem, long ToCoordSystem, long Displacement, VARIANT& OCSNormal)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &Point, FromCoordSystem, ToCoordSystem, Displacement, &OCSNormal);
		return result;
	}
	void InitializeUserInput(long Bits, VARIANT& KeyWordList)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Bits, &KeyWordList);
	}
	long GetInteger(VARIANT& Prompt)
	{
		long result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_I4, (void*)&result, parms, &Prompt);
		return result;
	}
	double GetReal(VARIANT& Prompt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020007, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &Prompt);
		return result;
	}
	CString GetInput()
	{
		CString result;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetKeyword(VARIANT& Prompt)
	{
		CString result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, &Prompt);
		return result;
	}
	CString GetString(long HasSpaces, VARIANT& Prompt)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, HasSpaces, &Prompt);
		return result;
	}
	double GetAngle(VARIANT& Point, VARIANT& Prompt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &Point, &Prompt);
		return result;
	}
	double AngleFromXAxis(VARIANT& StartPoint, VARIANT& EndPoint)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6002000c, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &StartPoint, &EndPoint);
		return result;
	}
	VARIANT GetCorner(VARIANT& Point, VARIANT& Prompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6002000d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &Point, &Prompt);
		return result;
	}
	double GetDistance(VARIANT& Point, VARIANT& Prompt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6002000e, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &Point, &Prompt);
		return result;
	}
	double GetOrientation(VARIANT& Point, VARIANT& Prompt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x6002000f, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &Point, &Prompt);
		return result;
	}
	VARIANT GetPoint(VARIANT& Point, VARIANT& Prompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60020010, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &Point, &Prompt);
		return result;
	}
	VARIANT PolarPoint(VARIANT& Point, double Angle, double Distance)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_R8 VTS_R8 ;
		InvokeHelper(0x60020011, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &Point, Angle, Distance);
		return result;
	}
	void CreateTypedArray(VARIANT * varArr, long Type, SAFEARRAY * inArgs)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_I4 /*VTS_NONE*/ VTS_PVARIANT ;
		InvokeHelper(0x60020012, DISPATCH_METHOD, VT_EMPTY, NULL, parms, varArr, Type, inArgs);
	}
	void GetEntity(LPDISPATCH * Object, VARIANT * PickedPoint, VARIANT& Prompt)
	{
		static BYTE parms[] = VTS_PDISPATCH VTS_PVARIANT VTS_VARIANT ;
		InvokeHelper(0x60020013, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Object, PickedPoint, &Prompt);
	}
	void Prompt(LPCTSTR Message)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020014, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Message);
	}
	void GetSubEntity(LPDISPATCH * Object, VARIANT * PickedPoint, VARIANT * transMatrix, VARIANT * ContextData, VARIANT& Prompt)
	{
		static BYTE parms[] = VTS_PDISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_VARIANT ;
		InvokeHelper(0x60020015, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Object, PickedPoint, transMatrix, ContextData, &Prompt);
	}
	BOOL IsURL(LPCTSTR URL)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020016, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, URL);
		return result;
	}
	void GetRemoteFile(LPCTSTR URL, BSTR * LocalFile, BOOL IgnoreCache)
	{
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_BOOL ;
		InvokeHelper(0x60020017, DISPATCH_METHOD, VT_EMPTY, NULL, parms, URL, LocalFile, IgnoreCache);
	}
	void PutRemoteFile(LPCTSTR URL, LPCTSTR LocalFile)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60020018, DISPATCH_METHOD, VT_EMPTY, NULL, parms, URL, LocalFile);
	}
	BOOL IsRemoteFile(LPCTSTR LocalFile, BSTR * URL)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x60020019, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, LocalFile, URL);
		return result;
	}
	BOOL LaunchBrowserDialog(BSTR * SelectedURL, LPCTSTR DialogTitle, LPCTSTR OpenButtonCaption, LPCTSTR StartPageURL, LPCTSTR RegistryRootKey, BOOL OpenButtonAlwaysEnabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x6002001a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SelectedURL, DialogTitle, OpenButtonCaption, StartPageURL, RegistryRootKey, OpenButtonAlwaysEnabled);
		return result;
	}

	// IAcadUtility properties
public:

};
