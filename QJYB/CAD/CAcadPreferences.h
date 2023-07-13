// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadPreferences wrapper class

class CAcadPreferences : public COleDispatchDriver
{
public:
	CAcadPreferences(){} // Calls COleDispatchDriver default constructor
	CAcadPreferences(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadPreferences(const CAcadPreferences& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadPreferences methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Files()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Display()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_OpenSave()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Output()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020004, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_System()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_User()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020006, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Drafting()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Selection()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020008, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Profiles()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020009, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// IAcadPreferences properties
public:

};
