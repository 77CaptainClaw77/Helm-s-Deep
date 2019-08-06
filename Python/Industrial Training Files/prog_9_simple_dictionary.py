mydict={'Ram':'1st Feb 2001','Shyam':'2nd March 2011','Raj':'7th May 1998'}
res=''
while res!='no':
    res=input("Enter Query Name : ")
    if res in mydict:
        print("QUERY FOUND!")
        print('Name : '+res)
        print('DOB : '+mydict[res])
    else:
        print('Query Not Found!. Creating new record ...')
        res_dob=input('Enter the DOB : ')
        mydict[res]=res_dob
    res=input("Do you want to continue ? ")



        