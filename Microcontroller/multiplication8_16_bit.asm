ORG 0x0
	SJMP 0X30
ORG 0X30
	MOV 0X40,#0XCD	
	MOV 0X51,#0XFF
	MOV 0X50,#0XFF
	MOV A,0X40
	MOV B,0X51
	MUL AB
	MOV 0X62,A
	MOV 0X55,B
	MOV A,0X40
	MOV B,0X50
	MUL AB
	MOV 0X56,B
	ADD A,0X55
	MOV 0X61,A
	MOV A,#00
	ADDC A,0X56
	MOV 0X60,A
LOOP:SJMP LOOP
END
