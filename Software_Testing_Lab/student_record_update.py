#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 17 14:53:24 2020

@author: kumarguru
"""
#%% Import section
import pandas as pd
#%% Read excel file
data=pd.read_excel("./StudentSheet.xlsx")
#%% Perform updates
for i,row in data.iterrows():
    flag=False
    for item in row[2:5]:
        if item<60:
            flag=True
            break
    if flag: 
        data.iloc[i,5]="Fail"
    else: 
        data.iloc[i,5]="Pass"
        
#%% Write updates
data.to_excel("./StudentSheet.xlsx",index=False)