from bs4 import BeautifulSoup
import requests
import html5lib
my_url="https://www.vocabulary.com/lists/141245"
raw_cont=requests.get(my_url)
soup= BeautifulSoup(raw_cont.text, 'html5lib')
word_list={}
word_list_unfil=soup.find('ol', attrs = {'id':'wordlist'})
for obj in word_list_unfil.findAll('li',attrs={'class':'entry learnable'}):
    word=(obj.find('a',attrs={'class':'word dynamictext'})).text
    word_def=(obj.find('div',attrs={'class':'definition'})).text
    word_list[word]=word_def
with open('WordList.txt','w') as f:
    for w,w_d in word_list.items():
        f.write(w+" : "+w_d+"\n")

        
