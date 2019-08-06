guest_dict={'Alice':{'apples':5,'pretzels':12},'Bob':{'ham sandwiches':3,'apples':2},'Carol':{'cups':3,'apple pies':1}}
count_dict=dict()
for i in guest_dict.keys():
    for j in guest_dict[i].keys():
        if j in count_dict:
            count_dict[j]=count_dict[j]+guest_dict[i][j]
        else:
            count_dict[j]=guest_dict[i][j]
for i,j in count_dict.items():
    print(i+':'+str(j))

