ORG 0X00
	SJMP 0X30
ORG 0X30
	MOV R1,#30
	MOV R2,#40
	XCH A,R1
	XCH A,R2
	XCH A,R1
LOOP:SJMP LOOP
END