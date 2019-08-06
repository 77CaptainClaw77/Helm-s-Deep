import logging
logging.basicConfig(filename="A:\\status.log",level= logging.DEBUG)
logger=logging.getLogger()
flag=0
def checktestint(d):
	try:
		d=int(d)
	except:
		d=-1
		flag=1
		logger.error('Non numeric data entered')
	finally:
		return d
print('Enter the three sides of a triangle')
a,b,c=input(),input(),input()
a=checktestint(a)
b=checktestint(b)
c=checktestint(c)
if a==b==c and a>=0:
    print('Equilateral')
elif a==b or a==b or a==c:
    print('Isoscles')
elif a==-1 or b==-1 or c==-1:
    print('Invalid Input')
    logger.info('UNSUCCESSFUL')
    quit()	
else:
    print('Scalene')
logger.info('SUCCESSFUL')
    
