testing
profile: nBytecodes
	"(NewspeakInterpreterSimulator new openOn: 'clonex.image') profile: 60000"
	transcript clear.
	byteCount := 0.
	MessageTally spyOn: [self runForNBytes: nBytecodes].
	self close