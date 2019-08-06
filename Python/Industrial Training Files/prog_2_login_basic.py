import random,sys
name=input("NAME : ")
flag=False
if name!="Ram":
    print("Invalid Username")    
    flag=True
else:
    password=input("PASSWORD : ")
    if password!="pass":
        print("Invalid Password")
        flag=True
if flag:
    print("Access Denied")
    sys.exit()
print("Accesss Granted")
print("Your Access KEY is "+ str(random.randint(143432,1223124)))
