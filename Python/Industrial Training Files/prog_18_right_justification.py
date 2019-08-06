mylist=[['jon','dany','jorah'],['sansa','theon','robin'],['brandon','catelyn','petyr'],['jamie','cersei','euron']]
max_len=0
for str_set in mylist:
    for st in str_set:
        if len(st)>max_len:
            max_len=len(st)
for st in mylist:
    for item in st:
        print(item.rjust(max_len+1),end='  ')
    print(' ')
