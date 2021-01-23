import os
import pathlib
counter={'.c':0,'.cpp':0,'.py':0,'.xlsx':0,'.jpg':0,'.tiff':0,'.java':0}
file_type_names={'.c':"C files",".cpp":"C++ files",'.py':'Python files','.xlsx':'Excel files','.jpg':'JPG image files','.tiff':'TIFF image files','.java':'Java files'}
dir_cnt=0
other_file_types=0
for root,dirs,files in os.walk('.'):
    for f in files:
        if pathlib.Path(f).suffix in counter.keys():
            counter[pathlib.Path(f).suffix]+=1
        # if '.'+f.split('.')[-1] in counter.keys():
        #     counter['.'+f.split('.')[-1]]+=1
        else:
            other_file_types+=1
    dir_cnt+=len(dirs)
for k in counter.keys():
    print("The number of "+file_type_names[k]+" is :"+str(counter[k]))
print("The number of other file types is: "+str(other_file_types))
print("The number of directories is: "+str(dir_cnt))
