a=int(input("Enter Range"))
flag=True
print("The prime numbers are ")
for i in range(2,a,1):
    for j in range(i-1,1,-1):
        if i%j==0:
            flag=False
    if flag:
        print(i)
    flag=True

