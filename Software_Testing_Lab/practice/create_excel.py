import pandas as pd
df=pd.read_excel("~/Desktop/StudentSheet.xlsx")
del_indices=[]
for i,r in df.iterrows():
    flag=False
    for j in r[2:5]:
        if j<60:
            flag=True
            break
    if not flag:
        del_indices.append(i)
df=df.drop(del_indices)
df.to_excel("./StudentData.xlsx",index=False)
