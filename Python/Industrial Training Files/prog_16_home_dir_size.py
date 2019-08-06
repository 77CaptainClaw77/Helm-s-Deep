import os
def recursive_mover(p,res):
    if not (p.__contains__('.')):
        for f in os.listdir(p):
            res=recursive_mover(os.path.join(p,f),res)
    else:
        res=res+(os.path.getsize(p))
    return res


print(recursive_mover("A:\\Prog\\ALL", 0))
