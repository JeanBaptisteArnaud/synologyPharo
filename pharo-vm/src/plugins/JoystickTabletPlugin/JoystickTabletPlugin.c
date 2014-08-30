/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f
   from
	JoystickTabletPlugin VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f
 */
static char __buildInfo[] = "JoystickTabletPlugin VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "JoystickTabletPlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
EXPORT(sqInt) initialiseModule(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveGetTabletParameters(void);
EXPORT(sqInt) primitiveReadJoystick(void);
EXPORT(sqInt) primitiveReadTablet(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*classBitmap)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*positive32BitIntegerFor)(sqInt integerValue);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt classBitmap(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt positive32BitIntegerFor(sqInt integerValue);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"JoystickTabletPlugin VMMaker.oscog-EstebanLorenzano.780 (i)"
#else
	"JoystickTabletPlugin VMMaker.oscog-EstebanLorenzano.780 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	// InterpreterPlugin>>#getInterpreter
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	// InterpreterPlugin>>#getModuleName
	return moduleName;
}

static sqInt
halt(void)
{
	// InterpreterPlugin>>#halt
	;
	return 0;
}

EXPORT(sqInt)
initialiseModule(void)
{
	// JoystickTabletPlugin>>#initialiseModule
	return joystickInit();
}

static sqInt
msg(char *s)
{
	// InterpreterPlugin>>#msg:
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}


/*	Get information on the pen tablet attached to this machine. Fail if there
	is no tablet. If successful, the result is an array of integers; see the
	Smalltalk call on this primitive for its interpretation.
 */

EXPORT(sqInt)
primitiveGetTabletParameters(void)
{
	// JoystickTabletPlugin>>#primitiveGetTabletParameters
	sqInt cursorIndex;
	sqInt result;
	int *  resultPtr;
	sqInt resultSize;

	cursorIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = instantiateClassindexableSize(classBitmap(), resultSize);
	resultPtr = ((int *)firstIndexableField(result));
	success(tabletGetParameters(cursorIndex, resultPtr));
	if (failed()) {
		return null;
	}
	popthenPush(2, result);
	return null;
}


/*	Read an input word from the joystick with the given index. */

EXPORT(sqInt)
primitiveReadJoystick(void)
{
	// JoystickTabletPlugin>>#primitiveReadJoystick
	sqInt index;
	sqInt _return_value;

	index = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	_return_value = positive32BitIntegerFor((joystickRead(index)));
	if (failed()) {
		return null;
	}
	popthenPush(2, _return_value);
	return null;
}


/*	Get the current state of the cursor of the pen tablet specified by my
	argument. Fail if there is no tablet. If successful, the result is an
	array of integers; see the Smalltalk call on this primitive for its
	interpretation. 
 */

EXPORT(sqInt)
primitiveReadTablet(void)
{
	// JoystickTabletPlugin>>#primitiveReadTablet
	sqInt cursorIndex;
	sqInt result;
	int *  resultPtr;
	sqInt resultSize;

	cursorIndex = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = instantiateClassindexableSize(classBitmap(), resultSize);
	resultPtr = ((int *)firstIndexableField(result));
	success(tabletRead(cursorIndex, resultPtr));
	if (failed()) {
		return null;
	}
	popthenPush(2, result);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	// InterpreterPlugin>>#setInterpreter:
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {

#if !defined(SQUEAK_BUILTIN_PLUGIN)
		classBitmap = interpreterProxy->classBitmap;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		popthenPush = interpreterProxy->popthenPush;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

EXPORT(sqInt)
shutdownModule(void)
{
	// JoystickTabletPlugin>>#shutdownModule
	return joystickShutdown();
}

static sqInt
sqAssert(sqInt aBool)
{
	// SmartSyntaxInterpreterPlugin>>#sqAssert:
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* JoystickTabletPlugin_exports[][3] = {
	{"JoystickTabletPlugin", "getModuleName", (void*)getModuleName},
	{"JoystickTabletPlugin", "initialiseModule", (void*)initialiseModule},
	{"JoystickTabletPlugin", "primitiveGetTabletParameters\000\000", (void*)primitiveGetTabletParameters},
	{"JoystickTabletPlugin", "primitiveReadJoystick\000\000", (void*)primitiveReadJoystick},
	{"JoystickTabletPlugin", "primitiveReadTablet\000\000", (void*)primitiveReadTablet},
	{"JoystickTabletPlugin", "setInterpreter", (void*)setInterpreter},
	{"JoystickTabletPlugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveGetTabletParametersAccessorDepth = 0;
signed char primitiveReadJoystickAccessorDepth = 0;
signed char primitiveReadTabletAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */