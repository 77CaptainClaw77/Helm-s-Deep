def qsort(nums,l,r):
    if l<r:
        piv=nums[r]
        j=l-1
        for i in range(l,r):
            if(nums[i]<piv):
                j+=1
                nums[i],nums[j]=nums[j],nums[i]
        nums[j+1],nums[r]=nums[r],nums[j+1]
        p=j+1
        qsort(nums,l,p-1)
        qsort(nums,p+1,r)
nums=list(map(int,input("Enter a space seperated list of numbers: ").split()))
qsort(nums,0,len(nums)-1)
print("Sorted List of Numbers is:- "+",".join(list(map(str,nums))))
