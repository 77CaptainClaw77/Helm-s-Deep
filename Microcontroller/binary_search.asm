ORG 0X00
	SJMP 0X30
ORG 0X30
	N EQU R2
	BASE EQU R0
	KEY EQU 0X60
	FOUND EQU 0X61
	MID EQU R4
	H EQU R5
	L EQU R6
	MOV FOUND,#00
	MOV A,N
	SUBB A,#0X01
	MOV H,A
	MOV L,#00
	MOV 0X63,BASE
COMPARE:MOV A,H
		MOV BASE,0X63
		SUBB A,L
		JC LOOP
		CLR C
		MOV A,H
		ADD A,L
		MOV B,#0X02
		DIV AB
		MOV MID,A
		MOV A,BASE
		ADD A,MID
		MOV BASE,A
		MOV A,@BASE
		CJNE A,KEY,NOTEQUAL
EQUAL:	MOV A,0X63
		ADD A,MID
		MOV FOUND,A		
	  SJMP LOOP
NOTEQUAL:JC GREATERTHAN
LESSERTHAN:MOV A,MID
			SUBB A,#0X01
			MOV H,A
			CLR C
			SJMP COMPARE
GREATERTHAN:MOV A,MID 
			ADD A,#0X01
			MOV L,A
			CLR C
			SJMP COMPARE		 
LOOP:SJMP LOOP
END 
