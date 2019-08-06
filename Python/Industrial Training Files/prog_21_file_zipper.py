import zipfile,os,sys
if len(sys.argv)!=4:
    print("Invalid Syntax!")
    print("Syntax: python prg_name cmd file_to_zip zip_file_name")
    sys.exit()
user_command=sys.argv[1]
file_to_zip=sys.argv[2]
zip_file_name=sys.argv[3]
os.chdir("A:")
my_cur_path=os.path.join("A:\\",file_to_zip)
if user_command=='zip':
    myzip=zipfile.ZipFile(os.path.join('A:\\',zip_file_name),'w')
    for folder,subfolders,files in os.walk(my_cur_path):
        myzip.write(folder)
        for f in files:
            myzip.write(os.path.join(folder,f))
    print(myzip.infolist())
    myzip.close()
elif user_command=='unzip':
    myzip = zipfile.ZipFile(os.path.join('A:\\', zip_file_name), 'r')
    if file_to_zip=='all':
        myzip.extractall("A:\\") 
    else:  
        myzip.extract(file_to_zip,'A:\\')
    myzip.close()    
else:
    print("Invalid usage")

'''
os.chdir("A:")
if sys.argv[3]=='zip':
    myzip=zipfile.ZipFile(sys.argv[2],'w')
    myzip.write(os.path.join("A:\\",sys.argv[1]))
    print(myzip.infolist())
    myzip.close()
elif sys.argv[3]=='unzip':
    myzip=zipfile.ZipFile(sys.argv[2],'w')
    if sys.argv[1]=='all':
        myzip.extractall()
        myzip.close()
    else:
        myzip.extract(sys.argv[1])
else:
    print("Syntax Error!")
'''
