class Bird:
    st='Bird is the word!'
    def __init__(self,name,type):
        self.name=name
        self.type=type
bjay=Bird('Jay','Bluejay')
wpe=Bird('Woody','Woodpecker')
print(bjay.__class__.st)
print("{} is a {}".format(bjay.name,bjay.type))
print("{} is a {}".format(wpe.name, wpe.type))
print(Bird.st)