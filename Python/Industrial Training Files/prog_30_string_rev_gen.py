def mygen(st): 
    for i in range(len(st)-1,-1,-1):yield st[i]
print(('').join(list(mygen(input("Enter a string:")))))
