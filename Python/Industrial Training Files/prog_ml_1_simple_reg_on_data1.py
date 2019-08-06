# -*- coding: utf-8 -*-
"""
Created on Tue Jun 11 08:33:35 2019

@author: Kumar's PC
"""
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
mydata=pd.read_csv('data1.csv')
X=mydata.iloc[:,:-1].values
Y=mydata.iloc[:,1].values
my_mod=LinearRegression()
my_mod.fit(X,Y)
#x_test=np.ndarray([])
my_prediction=my_mod.predict(X)