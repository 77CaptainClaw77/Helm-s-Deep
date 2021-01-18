li=list(map(int,input("Enter a space separated set of integers: ").split()))
pos=sum(x>=0 for x in li)
print("Number of positive integers: {}\nNumber of negative integers: {}\n".format(pos,len(li)-pos))
