ORG 0X00
	SJMP 0X30
ORG  0X30
	ST EQU R0 //START ADDRESS
	TT EQU R1 //TRANSFER ADDRESS
	N EQU R6 //NUMBER OF ELEMENTS
	//COUNT EQU R7
	MOV A,R1
	SUBB A,R0
	JC DOWNMOV
	MOV A,N
	ADD A,R0
	MOV R0,A
	MOV A,N
	ADD A,R1
	MOV R1,A
	DEC R0
	DEC R1
UPMOV:	MOV A,@R0
		MOV	@R1,A
		DEC R0
		DEC R1
		DEC N
		CJNE N,#00,UPMOV
	SJMP LOOP
DOWNMOV: MOV A,@R0
		MOV	@R1,A
		INC R0
		INC R1
		DEC N
		CJNE N,#00,DOWNMOV
LOOP:SJMP LOOP
END



