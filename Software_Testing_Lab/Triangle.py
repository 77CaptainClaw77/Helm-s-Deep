def isvalid(v): return v>0 and v<=10
a,b,c=-1,-1,-1
while True: 
    try: a,b,c=map(int,input("Enter the sides of the triangle: ").split())
    except: 
        print("Invalid input: Wrong format.")
        continue
    if isvalid(a) and isvalid(b) and isvalid(c): break
    else: print("Invalid input: Number out of bounds.")
if a+b<=c or a+c<=b or b+c<=a: print("Not a triangle!")
elif a==b and b==c: print("Equilateral Triangle")
elif a==b or b==c or a==c: print("Isoscles triangle")
else: print("Scalene Triangle")