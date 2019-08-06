def my_gen():
    n=1
    print('This is printed first')
    yield n
    n+=1
    print("Second")
    yield n
    n+=1
    print("Last")
    yield n
a=my_gen()
#print(list(a))
print(next(a))
print(next(a))
print(next(a))
#print(list(a))
#for i in mygen():
#    print(i)
