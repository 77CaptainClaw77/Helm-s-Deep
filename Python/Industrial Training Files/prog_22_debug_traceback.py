import traceback
#the error is not what is expected
a=input("Enter a number")
b=input("Enter a number")
try:
    if a<=0 or b<=0:
        raise Exception("Error has occured")
    print(a/b)
except:
    f=open("error_file.txt",'w')
    f.write(traceback.format_exc())
    f.close()