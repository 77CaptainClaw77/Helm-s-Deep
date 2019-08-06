temp_n=1
temp_p=0
temp_u=0
sum=1
for i in range(int(input('Enter the number of terms whose sum is to be determined'))-1):
	temp_u=temp_n
	temp_n=temp_n+temp_p
	temp_p=temp_u
	sum+=temp_n
print(sum)
