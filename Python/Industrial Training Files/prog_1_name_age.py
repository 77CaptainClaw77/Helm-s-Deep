a=input("Enter your name : ")
b=int(input("Enter your age : "))
if b<0 or b>150 or (b+5)>150:
	if b<0:
		print("\nTOO YOUNG")
	else:
		print("\nA Thing Of The Past")
	exit()
print("\nAfter 5 Years "+a+"'s age will be "+str(b+5))
b=b+5
mes='\n'
if b>100:
	mes=mes+"Fossil"
elif b>80:
	mes=mes+"Old"
elif b>60:
	mes=mes+"Senior"
elif b>30:
	mes=mes+"Middle-Aged"
elif b>20:
	mes=mes+"Young Adult"
elif b>10:
	mes=mes+"Teenager"
else:
	mes="Child"
print(mes)