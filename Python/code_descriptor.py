from os import listdir
from os.path import isfile, join
from bs4 import BeautifulSoup
import requests
from selenium import webdriver
from selenium.webdriver.firefox.options import Options
codechef_path="../C++/Codechef/"
file_list=[f for f in listdir(codechef_path) if isfile(join(codechef_path,f))]
modify_list=[]
problem_ids=[]
for f in file_list:
    openfile=open(join(codechef_path,f),'r')
    if openfile.read().find("/*File Information:-")==-1:
        modify_list.append(join(codechef_path,f))
        problem_ids.append(f.split('_')[0])
    openfile.close()
url_path="https://www.codechef.com/problems/"
comment_line="""/*File Information:-
Author: Kumarguru V
"""
prob_desc=[]
firefox_opt=webdriver.FirefoxOptions()
firefox_opt.set_headless()
for pid in problem_ids:
    driver=webdriver.Firefox(options=firefox_opt,executable_path="../../Geckodriver/geckodriver")
    driver.get(url_path+pid)
    soup=BeautifulSoup(driver.page_source,'lxml')
    ps=soup.find('div',{'id':'problem-statement'}).get_text()
    if ps.find("\nInput\n")!=-1:
        ps=ps[:ps.find("\nInput\n")]
    else:
        ps=ps[:ps.find("\nInput:\n")]
    prob_desc.append(ps)
    driver.close()
print(prob_desc)
for i in range(len(modify_list)):
    openfile=open(modify_list[i],'r+')
    prev_cont=openfile.read()
    openfile.seek(0,0)
    comment=comment_line+prob_desc[i]+"""
Link: """+url_path+problem_ids[i]+"""
*/
"""
    openfile.write(comment+prev_cont)
    openfile.close()
    

