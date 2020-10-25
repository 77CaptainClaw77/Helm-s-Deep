n1=int(input())
n2=int(input())
ans=1
tc=0
for i in range(n1,n2+1):
    ans=ans*i
while ans%10==0 and ans>0:
    ans=ans//10
    tc=tc+1
st_ans=str(ans)
final_ans=""
if len(st_ans)>10:
    final_ans=st_ans[0:5]+"..."+st_ans[-5:]+" * 10^"+str(tc)
else:
    final_ans=st_ans+" * 10^"+str(tc)
print(final_ans)

