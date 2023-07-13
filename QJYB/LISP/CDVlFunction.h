// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard
#pragma  once
//#import "vl16.tlb" no_namespace
// CDVlFunction wrapper class
class CDVlFunction : public COleDispatchDriver
{
public:
	CDVlFunction(){} // Calls COleDispatchDriver default constructor
	CDVlFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDVlFunction(const CDVlFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	void Release()
	{
		ReleaseDispatch();
	}

	// Attributes
public:

	// Operations
public:


	// DVlFunction methods
public:
	//无参数
	VARIANT funcall(SAFEARRAY * Arguments)
	{
		VARIANT result;
		//static BYTE parms[] = VTS_NONE ;
		static BYTE * parms = VTS_NONE ;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Arguments);
		return result;
	}
    //参数是字符串
	VARIANT funcall(BSTR Arguments)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR; 
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Arguments);
		return result;
	}

    //参数是整数
	VARIANT funcall(long Arguments)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4; 
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Arguments);
		return result;
	}
	//参数是实数
	VARIANT funcall(double Arguments)
	{
		VARIANT result;
		static BYTE parms[] = VTS_R8; 
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Arguments);
		return result;
	}

	//参数是变量	
	VARIANT funcall(const VARIANT & Arguments)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT; 
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Arguments);
		return result;
	}

	//Active对象
	VARIANT funcall(const IDispatch * pArguments)
	{
		VARIANT result;
		static BYTE parms[] = VTS_DISPATCH;  
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, pArguments);
		return result;
	} 
   
	//未知参数
	VARIANT funcall(const void* pArguments)
	{
		VARIANT result;
		static BYTE parms[] = VTS_UNKNOWN; 
		InvokeHelper(0x0, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, pArguments);
		return result;
	} 


	CString get_Name()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// DVlFunction properties
public:

};
