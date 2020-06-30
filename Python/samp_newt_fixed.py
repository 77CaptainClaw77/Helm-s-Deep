import math
def newt(z,w0):
    lim=pow(10,-10)
    est=2*lim
    wp=w0
    iter=0
    maxiter=100
    while est>tol and iter<maxiter:
        iter=iter+1
        w=wp+ math.sin(wp)