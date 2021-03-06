/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f
   from
	DropPlugin VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f
 */
static char __buildInfo[] = "DropPlugin VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f " __DATE__ ;



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

#include "DropPlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
EXPORT(sqInt) initialiseModule(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveDropRequestFileHandle(void);
EXPORT(sqInt) primitiveDropRequestFileName(void);
EXPORT(sqInt) setFileAccessCallback(int address);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*methodArgumentCount)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*primitiveFail)(void);
static sqInt (*push)(sqInt object);
static sqInt (*stackIntegerValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt methodArgumentCount(void);
extern sqInt pop(sqInt nItems);
extern sqInt primitiveFail(void);
extern sqInt push(sqInt object);
extern sqInt stackIntegerValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"DropPlugin VMMaker.oscog-EstebanLorenzano.780 (i)"
#else
	"DropPlugin VMMaker.oscog-EstebanLorenzano.780 (e)"
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
	// DropPlugin>>#initialiseModule
	return dropInit();
}

static sqInt
msg(char *s)
{
	// InterpreterPlugin>>#msg:
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}


/*	Note: File handle creation needs to be handled by specific support code
	explicitly bypassing the plugin file sand box.
 */

EXPORT(sqInt)
primitiveDropRequestFileHandle(void)
{
	// DropPlugin>>#primitiveDropRequestFileHandle
    sqInt dropIndex;
    sqInt handleOop;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	dropIndex = stackIntegerValue(0);

	/* dropRequestFileHandle needs to return the actual oop returned */

handleOop = dropRequestFileHandle(dropIndex);
	if (!(failed())) {
		pop(2);
		push(handleOop);
	}
}


/*	Note: File handle creation needs to be handled by specific support code
	explicitly bypassing the plugin file sand box.
 */

EXPORT(sqInt)
primitiveDropRequestFileName(void)
{
	// DropPlugin>>#primitiveDropRequestFileName
    sqInt dropIndex;
    char *dropName;
    sqInt i;
    sqInt nameLength;
    sqInt nameOop;
    char *namePtr;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	dropIndex = stackIntegerValue(0);

	/* dropRequestFileName returns name or NULL on error */

dropName = dropRequestFileName(dropIndex);
	if (dropName == null) {
return primitiveFail();
	}
	nameLength = strlen(dropName);
	nameOop = instantiateClassindexableSize(classString(), nameLength);
	namePtr = firstIndexableField(nameOop);
	for (i = 0; i < nameLength; i += 1) {
namePtr[i] = (dropName[i]);
	}
	pop(2);
	push(nameOop);
}

EXPORT(sqInt)
setFileAccessCallback(int address)
{
	// DropPlugin>>#setFileAccessCallback:
	return sqSecFileAccessCallback((void *) address);
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
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		pop = interpreterProxy->pop;
		primitiveFail = interpreterProxy->primitiveFail;
		push = interpreterProxy->push;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

EXPORT(sqInt)
shutdownModule(void)
{
	// DropPlugin>>#shutdownModule
	return dropShutdown();
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* DropPlugin_exports[][3] = {
	{"DropPlugin", "getModuleName", (void*)getModuleName},
	{"DropPlugin", "initialiseModule", (void*)initialiseModule},
	{"DropPlugin", "primitiveDropRequestFileHandle\000\000", (void*)primitiveDropRequestFileHandle},
	{"DropPlugin", "primitiveDropRequestFileName\000\000", (void*)primitiveDropRequestFileName},
	{"DropPlugin", "setFileAccessCallback", (void*)setFileAccessCallback},
	{"DropPlugin", "setInterpreter", (void*)setInterpreter},
	{"DropPlugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDropRequestFileHandleAccessorDepth = 0;
signed char primitiveDropRequestFileNameAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
