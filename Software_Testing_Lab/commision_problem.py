lock_price,stock_price,barrel_price=[45,30,25]
tl,ts,tb=0,0,0
while True:
    try:
        locks,stocks,barrels=map(int,input("Enter the number of locks,stocks and barrels:- ").split())
    except:
        print("Invalid Input Type Error!")
    if locks==-1:
        break
    if stocks<=-1 or locks<-1 or barrels<=-1:
        print("Invalid Input Out of Range Error!")
        break
    tl,ts,tb=tl+locks,ts+stocks,tb+barrels
    if tl>70 or tb>90 or ts>80:
        print("Production Limit Exceeded!Re-enter the values:- ")
        tl,ts,tb=tl-locks,ts-stocks,tb-barrels
total_sales=tl*lock_price+tb*barrel_price+ts*stock_price
print("Total Sales Made: {}".format(total_sales))
commission=0
if total_sales>1800:
    commission=0.10*1000+0.15*800+(total_sales-1800)*0.2
elif total_sales>1000:
    commission=0.10*1000+0.15*(total_sales-1000)
else:
    commission=0.10*total_sales
print("Total Commission: {}".format(commission))
