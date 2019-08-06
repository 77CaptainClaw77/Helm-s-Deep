import pyperclip
new_list=[]
for line in (pyperclip.paste()).split('\n'): new_list.append('* '+line)
pyperclip.copy(('\n').join(new_list))