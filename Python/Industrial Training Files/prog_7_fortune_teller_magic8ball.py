import random
response=""
print("Future Bot 3000")
print("Step Right Up And Discover Your Future!!")
while response!="no":
    response=input("Your Question : ")
    soln=random.randint(1,5)
    if soln==1:
        print("Yes, Definitely!")
    elif soln==2:
        print("I don't think so")
    elif soln==3:
        print("No, not at all")
    elif soln==4:
        print("Anytime now")
    else:
        print("Patience is the key")
    response=input("Do you want to continue?")
print("Thank You For Using Future Bot 3000")
#or use a list like this
#response_list=["Yes, Definitely!","No, not at all","I don't think so","Anytime now"]
#then use random var-1 or -var to generate a random response
