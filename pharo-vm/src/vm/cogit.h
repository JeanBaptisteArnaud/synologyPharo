/* Automatically generated by
	CCodeGenerator VMMaker.oscog-EstebanLorenzano.780 uuid: b6f56292-e485-4a4e-8979-40c11b55ec4f
 */


/*** Function Prototypes ***/


#if defined(PRODUCTION) && !PRODUCTION && defined(__GNUC__) && !defined(NoDbgRegParms)
# define NoDbgRegParms __attribute__ ((regparm (0)))
#endif

#if !defined(NoDbgRegParms)
# define NoDbgRegParms /*empty*/
#endif

sqInt abortOffset(void);
void addCogMethodsToHeapMap(void);
sqInt bytecodePCForstartBcpcin(sqInt mcpc, sqInt startbcpc, CogBlockMethod *cogMethod);
sqInt canLinkToYoungClasses(void);
sqInt ceCPICMissreceiver(CogMethod *cPIC, sqInt receiver);
sqInt ceSICMiss(sqInt receiver);
void checkAssertsEnabledInCogit(void);
sqInt checkIntegrityOfObjectReferencesInCode(sqInt fullGCFlag);
char * codeEntryFor(char *address);
char * codeEntryNameFor(char *address);
sqInt cogCodeBase(void);
sqInt cogCodeConstituents(void);
void cogitPostGCAction(sqInt gcMode);
sqInt cogMethodDoesntLookKosher(CogMethod *cogMethod);
CogMethod * cogMNUPICSelectormethodOperandnumArgs(sqInt selector, sqInt methodOperand, sqInt numArgs);
CogMethod * cogselector(sqInt aMethodObj, sqInt aSelectorOop);
void compactCogCompiledCode(void);
void enterCogCodePopReceiver(void);
void enterCogCodePopReceiverAndClassRegs(void);
void enterCogCodePopReceiverArg0Regs(void);
void enterCogCodePopReceiverArg1Arg0Regs(void);
CogBlockMethod * findMethodForStartBcpcinHomeMethod(sqInt startbcpc, CogMethod *cogMethod);
void freeUnmarkedMachineCode(void);
sqInt genQuickReturnConst(void);
sqInt genQuickReturnInstVar(void);
sqInt genQuickReturnSelf(void);
void initializeCodeZoneFromupTo(sqInt startAddress, sqInt endAddress);
sqInt interpretOffset(void);
sqInt isPCWithinMethodZone(char *address);
sqInt isSendReturnPC(sqInt retpc);
void linkSendAtintooffsetreceiver(sqInt callSiteReturnAddress, CogMethod *sendingMethod, CogMethod *targetMethod, sqInt theEntryOffset, sqInt receiver);
void mapObjectReferencesInMachineCode(sqInt gcMode);
void markAndTraceMachineCodeOfMarkedMethods(void);
void markAndTraceObjectsOrFreeMachineCode(sqInt inFullGC);
void markMethodAndReferents(CogBlockMethod *aCogMethod);
usqInt maxCogMethodAddress(void);
usqInt mcPCForBackwardBranchstartBcpcin(sqInt bcpc, sqInt startbcpc, CogBlockMethod *cogMethod);
CogMethod * methodFor(void *address);
sqInt minCogMethodAddress(void);
sqInt mnuOffset(void);
sqInt numMethodsOfType(sqInt cogMethodType);
sqInt numRegArgs(void);
sqInt patchToOpenPICFornumArgsreceiver(sqInt selector, sqInt numArgs, sqInt receiver);
sqInt pcisWithinMethod(char *address, CogMethod *cogMethod);
void printCogMethodFor(void *address);
void printCogMethods(void);
void printCogMethodsOfType(sqInt cmType);
void printCogMethodsWithMethod(sqInt methodOop);
void printCogMethodsWithPrimitive(sqInt primIdx);
void printCogMethodsWithSelector(sqInt selectorOop);
void printCogYoungReferrers(void);
void printOpenPICList(void);
void printTrampolineTable(void);
void recordCallOffsetInof(CogMethod *cogMethod, void *callLabelArg);
sqInt recordPrimTraceFunc(void);
void rewritePrimInvocationInto(CogMethod *cogMethod, void (*primFunctionPointer)(void));
void setBreakMethod(sqInt anObj);
void setPostCompileHook(void (*aFunction)(CogMethod *, void *));
void setSelectorOfto(CogMethod *cogMethod, sqInt aSelectorOop);
sqInt traceLinkedSendOffset(void);
void unlinkAllSends(void);
void unlinkSendsOfisMNUSelector(sqInt selector, sqInt isMNUSelector);
void unlinkSendsToFree(void);
void unlinkSendsToandFreeIf(sqInt targetMethodObject, sqInt freeIfTrue);
void voidCogCompiledCode(void);
char * whereIsMaybeCodeThing(sqInt anOop);


/*** Global Variables ***/
VM_EXPORT sqInt blockNoContextSwitchOffset;
VM_EXPORT sqInt breakPC;
VM_EXPORT void * CFramePointer;
VM_EXPORT void * CStackPointer;
VM_EXPORT sqInt ceBaseFrameReturnTrampoline;
VM_EXPORT sqInt ceCannotResumeTrampoline;
VM_EXPORT void (*ceCaptureCStackPointers)(void);
VM_EXPORT sqInt ceCheckForInterruptTrampoline;
VM_EXPORT void (*ceEnter0ArgsPIC)(void);
VM_EXPORT void (*ceEnter1ArgsPIC)(void);
VM_EXPORT void (*ceEnter2ArgsPIC)(void);
VM_EXPORT void (*ceEnterCogCodePopReceiverAndClassRegs)(void);
VM_EXPORT void (*ceEnterCogCodePopReceiverArg0Regs)(void);
VM_EXPORT void (*ceEnterCogCodePopReceiverArg1Arg0Regs)(void);
VM_EXPORT void (*ceEnterCogCodePopReceiverReg)(void);
VM_EXPORT unsigned long (*ceGetSP)(void);
VM_EXPORT sqInt ceReturnToInterpreterTrampoline;
VM_EXPORT unsigned long (*ceTryLockVMOwner)(void);
VM_EXPORT void (*ceUnlockVMOwner)(void);
VM_EXPORT sqInt cFramePointerInUse;
VM_EXPORT sqInt cmEntryOffset;
VM_EXPORT sqInt cmNoCheckEntryOffset;
VM_EXPORT unsigned long debugPrimCallStackOffset;
VM_EXPORT void (*realCEEnterCogCodePopReceiverAndClassRegs)(void);
VM_EXPORT void (*realCEEnterCogCodePopReceiverArg0Regs)(void);
VM_EXPORT void (*realCEEnterCogCodePopReceiverArg1Arg0Regs)(void);
VM_EXPORT void (*realCEEnterCogCodePopReceiverReg)(void);
VM_EXPORT int traceFlags ;
VM_EXPORT sqInt traceStores;


/*** Macros ***/
#define blockAlignment(self) 8
#define breakOnImplicitReceiver() (traceFlags & 64)
#define ceBaseFrameReturnPC() ceBaseFrameReturnTrampoline
#define ceCannotResumePC() ((usqInt)ceCannotResumeTrampoline)
#define ceReturnToInterpreterPC() ((usqInt)ceReturnToInterpreterTrampoline)
#define dynSuperEntryOffset() cmDynSuperEntryOffset
#define entryOffset() cmEntryOffset
#define getCFramePointer() CFramePointer
#define getCStackPointer() CStackPointer
#define noCheckEntryOffset() cmNoCheckEntryOffset
#define noContextSwitchBlockEntryOffset() blockNoContextSwitchOffset
#define printOnTrace() (traceFlags & 1)
#define recordBlockTrace() (traceFlags & 4)
#define recordEventTrace() (traceFlags & 16)
#define recordOverflowTrace() (traceFlags & 32)
#define recordPrimTrace() (traceFlags & 8)
#define recordSendTrace() (traceFlags & 2)
#define setCFramePointer(theFP) (CFramePointer = (void *)(theFP))
#define setCStackPointer(theSP) (CStackPointer = (void *)(theSP))
#define tryLockVMOwner() (ceTryLockVMOwner() != 0)
#define unlockVMOwner() ceUnlockVMOwner()

