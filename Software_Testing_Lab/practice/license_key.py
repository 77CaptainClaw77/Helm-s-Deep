import pandas as pd
import re
df=pd.read_excel("licenses.xlsx")
print("Valid Keys are:-")
for i,r in df.iterrows():
    print(r)
    if re.search('[0-9]{16}',str(r[1])):
        print(r[1])
