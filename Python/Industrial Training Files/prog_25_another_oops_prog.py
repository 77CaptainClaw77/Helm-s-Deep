class employee:
    def __init__(self,name,salary):
        self.__name=name  #private var
        self.salary=salary ##Constructors are private
    def display(self):
        print("Name: {}".format(self.__name))
        print("Salary: {}".format(self.salary))
    def __secret(self):
        self.salary+=45
    def increment(self,p):
        self.salary=self.salary+(self.salary*p)/100
        self.__secret() #calling private function
Emp1=employee('Kumar',2130)
Emp1.display()
Emp1.increment(10)
Emp1.display()
Emp1._employee__name="not me" #Accessing a private variable
print(Emp1._employee__name)
Emp1.display()
#the del keyword can delete vars!
del Emp1.salary
#Emp1.display() will throw AttributeError as there is no salary variable
