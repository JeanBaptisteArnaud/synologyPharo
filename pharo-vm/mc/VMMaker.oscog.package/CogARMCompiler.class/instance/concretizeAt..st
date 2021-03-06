generate machine code
concretizeAt: actualAddress
	"Generate concrete machine code for the instruction at actualAddress,
	 setting machineCodeSize, and answer the following address."

	self assert: actualAddress \\ 4 = 0.
	address := actualAddress.
	self dispatchConcretize.
	self assert: (maxSize = nil or: [maxSize >= machineCodeSize]).
	^actualAddress + machineCodeSize