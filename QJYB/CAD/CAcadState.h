// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "acad.tlb" no_namespace
// CAcadState wrapper class

class CAcadState : public COleDispatchDriver
{
public:
	CAcadState(){} // Calls COleDispatchDriver default constructor
	CAcadState(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAcadState(const CAcadState& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IAcadState methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsQuiescent()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	// IAcadState properties
public:

};
