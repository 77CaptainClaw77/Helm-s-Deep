import sys
def all_op(a,b):
    try:
        x=a/b
    except Exception as e:  #can also catch ArithmeticError object as exception
        print("Invalid Input")  #except ArithmeticError:
        print("Error : ",end='')
        print(e)
        sys.exit()
    else:
        print("All operations Successful")
    return a+b,a-b,a*b,a/b,a**b,a//b,a%b
if __name__=="__main__":
    a=int(input("Enter the first number : "))
    b=int(input("Enter the second number : "))
    ans_list=all_op(a,b)
    sum_ans,diff,prod,div,power,int_div,mod=all_op(a,b)
    print("Sum is "+str(sum_ans))
    print("Difference is "+str(diff))
    print("Product is "+str(prod))
    print("Quotient is "+str(div))
    print("Power is "+str(power))
    print("Integral_Quotient is "+str(int_div))
    print("Remainder is "+str(mod))
