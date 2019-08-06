mydict=dict()
mes=input("Enter string : ")
for i in mes:
    if mydict.get(i,0)!=0:
        mydict[i]=mydict[i]+1
    else:
        mydict[i]=1
for i,j in mydict.items():
    print('Number of '+i+"'s = "+str(j))
