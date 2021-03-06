deprecated
setSigChldHandler
	"Set the SIGCHLD signal handler in the virtual machine."

	<returnTypeC: 'void'>
	| sigchldHandlerAction |
	<var: 'sigchldHandlerAction' type: #'struct sigaction'>
	self cppIf: #'SA_NOCLDSTOP' defined
		ifTrue:
			[self cCode: 'sigchldHandlerAction.sa_sigaction = reapChildProcess'
				inSmalltalk: [sigchldHandlerAction touch].
			self cCode: 'sigchldHandlerAction.sa_flags = SA_NODEFER | SA_NOCLDSTOP'.
			self needSigaltstack ifTrue:
				[self cCode: 'sigchldHandlerAction.sa_flags |= SA_ONSTACK'].
			self cCode: 'sigemptyset(&sigchldHandlerAction.sa_mask)'.
			((self cCode: 'sigaction(SIGCHLD, &sigchldHandlerAction, 0)' inSmalltalk: [self sigErrorNumber]) == self sigErrorNumber)
				ifTrue: [self perror: 'signal']]
		ifFalse:
			[self setSignalNumber: #SIGCHLD handler: #reapChildProcess]