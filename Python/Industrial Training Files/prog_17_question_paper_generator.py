import random,os,re
mydict =   {'Alabama': 'Montgomery', 'Alaska': 'Juneau', 'Arizona': 'Phoenix','Arkansas': 'Little Rock', 'California': 'Sacramento', 'Colorado': 'Denver','Connecticut': 'Hartford', 'Delaware': 'Dover', 'Florida': 'Tallahassee','Georgia': 'Atlanta', 'Hawaii': 'Honolulu', 'Idaho': 'Boise', 'Illinois':'Springfield', 'Indiana': 'Indianapolis', 'Iowa': 'Des Moines', 'Kansas':'Topeka', 'Kentucky': 'Frankfort', 'Louisiana': 'Baton Rouge', 'Maine':'Augusta', 'Maryland': 'Annapolis', 'Massachusetts': 'Boston', 'Michigan':'Lansing', 'Minnesota': 'Saint Paul', 'Mississippi': 'Jackson', 'Missouri':'Jefferson City', 'Montana': 'Helena', 'Nebraska': 'Lincoln', 'Nevada':'Carson City', 'New Hampshire': 'Concord', 'New Jersey': 'Trenton', 'NewMexico': 'Santa Fe', 'New York': 'Albany', 'North Carolina': 'Raleigh','North Dakota': 'Bismarck', 'Ohio': 'Columbus', 'Oklahoma': 'Oklahoma City','Oregon': 'Salem', 'Pennsylvania': 'Harrisburg', 'Rhode Island': 'Providence','South Carolina': 'Columbia', 'South Dakota': 'Pierre', 'Tennessee':'Nashville', 'Texas': 'Austin', 'Utah': 'Salt Lake City', 'Vermont':'Montpelier', 'Virginia': 'Richmond', 'Washington': 'Olympia', 'WestVirginia': 'Charleston', 'Wisconsin': 'Madison', 'Wyoming': 'Cheyenne'}
question_set=[]
for i in mydict.keys():
    question_set.append("What is the capital of "+i+'?')
ques_reg_exp = re.compile(r'of ([\s\w]*)\?')
for i in range(35):
    f=open('Paper No '+str(i+1)+'.txt','w')
    random.shuffle(question_set)
    answer_set=[]
    for j in range(50):
        reg_res=ques_reg_exp.search(question_set[j])
        answer_set=random.sample(list(mydict.values()),3)
        answer_set.append(mydict[reg_res.group(1)])
        while len(answer_set)>len(set(answer_set)):
            answer_set = random.sample(list(mydict.values()), 3)
            answer_set.append(mydict[reg_res.group(1)])
        random.shuffle(answer_set)
        f.write("\n"+str(j+1)+") "+question_set[j]+'\na)'+answer_set[0]+'\nb) '+answer_set[1]+'\nc) '+answer_set[2]+'\nd) '+answer_set[3]+'\n')
    f.close()


'''myl=list(mydict.keys())
for i in myl:
    question_set.append(question+str(i)+" ?")
cur_path=os.getcwd()
paper_names=[]
for i in range(35):
    paper_names.append('Paper '+str(i+1)+".txt")
for i in range(35):
    random.shuffle(question_set)
    myl = list(mydict.keys())
    q_file=open(paper_names[i],'w')
   # print(paper_name+str(i+1)+".txt")
    for j in range(50):
        answer_set=random.sample(list(mydict.values()),3)
        answer_set.append(mydict[myl[j]])
        random.shuffle(answer_set)
        q_file.write("\n"+str(j+1)+") "+question_set[j]+'\na)'+answer_set[0]+'\nb) '+answer_set[1]+'\nc) '+answer_set[2]+'\nd) '+answer_set[3])
    q_file.close()
'''
