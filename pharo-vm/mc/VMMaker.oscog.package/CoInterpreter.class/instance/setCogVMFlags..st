internal interpreter access
setCogVMFlags: flags
	"Set an array of flags indicating various properties of the Cog VM.
	 Bit 0: if set, implies the image's Process class has threadId as its 3rd inst var (zero relative)
	 Bit 1: if set, methods that are interpreted will have the flag bit set in their header
	 Bit 2: if set, implies preempting a process does not put it to the back of its run queue
	 Bit 3: if set, implies a threaded VM will not dosown the VM if owned by the GUI thread."
	flags asUnsignedInteger > 15 ifTrue:
		[^self primitiveFailFor: PrimErrUnsupported].
	processHasThreadId := (flags bitAnd: 1) ~= 0.
	flagInterpretedMethods := (flags bitAnd: 2) ~= 0.
	preemptionYields := (flags bitAnd: 4) = 0.
	noThreadingOfGUIThread := (flags bitAnd: 8) ~= 0