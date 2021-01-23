#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 17 15:04:11 2020

@author: kumarguru
"""
#%% Import section
import pandas as pd
#%% Read excel file
data=pd.read_excel("~/Desktop/StudentSheet.xlsx")
dels=[]
#%% Select records
for i,row in data.iterrows():
    flag=False
    for item in row[2:5]:
        if item<60:
            flag=True
            break
    if flag: 
        dels.append(i)
#%% Write data to new file
data=data.drop(data.index[dels])
data.to_excel("./StudentNames.xlsx",index=False)
# df=pd.DataFrame(names,columns=["Student Name"])
# df.to_excel("./StudentNames.xlsx",index=False)
