import sys,pyperclip,shelve,os
if len(sys.argv)!=2:
    print("Enter the command in the form: python prg command")
    sys.exit()
command=sys.argv[1]
os.chdir("A:\\")
shel_file=shelve.open('Multiclip')
counter=0 #an alternative an simpler method is to not use this variable
if len(list(shel_file.keys()))==0:
    shel_file['counter']=0    # Instead here for new_key_name use it as
if command=='save':
    counter=shel_file['counter']  #new_key_name='Key'+str(len(list(shel_file.keys()))
    new_key_name='Key'+str(counter)
    shel_file['counter']=counter+1
    my_data=pyperclip.paste()
    shel_file[new_key_name]=my_data
    print('Success!')
elif command=='list':
    if shel_file['counter']==0:
        print("No keys yet!")
    else:
        print('The keys are :- ')
        for i in list(shel_file.keys()):
            if i!='counter':
                print(i)
else:
    if command in list(shel_file.keys()):
        pyperclip.copy(shel_file[command])
        print('Data Copied To Clipboard')
    else:
        print('No such key exists!')
shel_file.close()