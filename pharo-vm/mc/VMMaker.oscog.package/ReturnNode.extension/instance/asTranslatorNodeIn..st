*VMMaker-C translation
asTranslatorNodeIn: aTMethod
	"Make a CCodeGenerator equivalent of a return."
	| exprTranslation lastExpr |
	exprTranslation := expr asTranslatorNodeIn: aTMethod.
	(expr isMessage
	 and: [expr receiver isVariableNode
	 and: [expr receiver key = 'super'
	 and: [exprTranslation isStmtList]]]) ifTrue:
		["super expansions containing returns are fine, and (as of 6/25/2012 19:27) the last
		  return is elided from the expansion by TMethod>>superExpansionNodeFor:args:. 
		  So we need to ensure the last expression is a return and simply reuse any other
		  returns in the expansion."
		exprTranslation statements last isReturn ifFalse:
			[lastExpr := exprTranslation statements removeLast.
			 exprTranslation statements addLast:
				(TReturnNode new 
					setExpression: lastExpr;
					comment: comment;
					yourself)].
		 ^exprTranslation].
	^TReturnNode new 
		setExpression: exprTranslation;
		comment: comment;
		yourself