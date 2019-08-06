class Point:
    def __init__(self,x=0,y=0):
        self.x=x
        self.y=y
    def __add__(self,other):
        return Point(self.x+other.x,self.y+other.y)
    def __str__(self):
        return "({0},{1})".format(self.x,self.y)
    def display(self):
        print("X = ",self.x,"\tY = ",self.y)
p1=Point(4,5)
p2=Point(45,21)
p3=p1+p2
p3.display()
print("Result=",p1+p2)  #Even str(p) will work because of the overload
print(str(p3))