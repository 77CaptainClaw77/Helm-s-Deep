class PowTwo:
    def __init__(self,lim=0):
        self.lim=lim
    def __iter__(self):
        self.n=0
        return self
    def __next__(self):
        if self.n<=self.lim :
            res=2**self.n
            self.n+=1
            return res
        else:
            raise StopIteration
a=PowTwo(1000)
my_iter=iter(a)
print(list(my_iter))