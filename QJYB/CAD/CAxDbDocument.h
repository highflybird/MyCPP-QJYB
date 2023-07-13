// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

//#import "axdb16enu.tlb" no_namespace
// CAxDbDocument wrapper class

class CAxDbDocument : public COleDispatchDriver
{
public:
	CAxDbDocument(){} // Calls COleDispatchDriver default constructor
	CAxDbDocument(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAxDbDocument(const CAxDbDocument& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAxDbDocument methods
public:
	LPDISPATCH get_ModelSpace()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_PaperSpace()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Blocks()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT CopyObjects(VARIANT& Objects, VARIANT& Owner, VARIANT * IdPairs)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_PVARIANT ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &Objects, &Owner, IdPairs);
		return result;
	}
	LPDISPATCH get_Groups()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_DimStyles()
	{
		LPDISPATCH result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Layers()
	{
		LPDISPATCH result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Linetypes()
	{
		LPDISPATCH result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Dictionaries()
	{
		LPDISPATCH result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_RegisteredApplications()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_TextStyles()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_UserCoordinateSystems()
	{
		LPDISPATCH result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Views()
	{
		LPDISPATCH result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Viewports()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	double get_ElevationModelSpace()
	{
		double result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_ElevationModelSpace(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	double get_ElevationPaperSpace()
	{
		double result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
		return result;
	}
	void put_ElevationPaperSpace(double newValue)
	{
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Limits()
	{
		VARIANT result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Limits(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	LPDISPATCH HandleToObject(LPCTSTR Handle)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Handle);
		return result;
	}
	LPDISPATCH ObjectIdToObject(long ObjectID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ObjectID);
		return result;
	}
	LPDISPATCH get_Layouts()
	{
		LPDISPATCH result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_PlotConfigurations()
	{
		LPDISPATCH result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Preferences()
	{
		LPDISPATCH result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_FileDependencies()
	{
		LPDISPATCH result;
		InvokeHelper(0x46, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_SummaryInfo()
	{
		LPDISPATCH result;
		InvokeHelper(0x47, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x100, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void Open(LPCTSTR FileName, VARIANT& Password)
	{
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, &Password);
	}

	void Open(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	void Save()
	{
		InvokeHelper(0x102, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SaveAs(LPCTSTR FileName, VARIANT& vSecurityParams)
	{
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x103, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, &vSecurityParams);
	}
	void SaveAs(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x103, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	void DxfIn(LPCTSTR FileName, VARIANT& LogFileName)
	{
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x104, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, &LogFileName);
	}
	void DxfOut(LPCTSTR FileName, VARIANT& precision, VARIANT& SaveThumbnailImage)
	{
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x105, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, &precision, &SaveThumbnailImage);
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x106, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Database()
	{
		LPDISPATCH result;
		InvokeHelper(0x107, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// IAxDbDocument properties
public:

};
