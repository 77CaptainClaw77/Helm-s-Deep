def quicksort(arr,st,end):
    if st>=end: return
    gi=end
    li=gi-1
    p=arr[st]
    while li>0:
        if arr[li]>p:
            gi=gi-1
            arr[gi],arr[li]=arr[li],arr[gi]
        li=li-1
    arr[st],arr[gi-1]=arr[gi-1],arr[st]
    quicksort(arr,st,gi-1)
    quicksort(arr,gi,end)
arr=[]
while True:
    try:
        arr=list(map(int,input("Enter the numbers: ").split()))
        break
    except: print("Invalid input!")
quicksort(arr,0,len(arr))
print(' '.join(list(map(str,arr))))