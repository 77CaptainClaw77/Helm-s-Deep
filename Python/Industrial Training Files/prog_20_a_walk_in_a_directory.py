import os
for folder_name, subfolder_name, file_name in os.walk('A:\\Delicious'):
    print("Folder Name: "+folder_name)
    for sub in subfolder_name:
        print("Subfolder Name: "+sub)
    for f in file_name:
        print("File Name: "+f)
    print('')