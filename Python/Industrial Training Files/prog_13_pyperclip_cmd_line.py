import sys,pyperclip,selenium
pass_dict={'gmail':{'kumar':'alpha'},'fb':{'sagar':'beta'},'snap':{'raahul':'charlie'},'insta':{'satvik':'poly'}}
if len(sys.argv)!=3:
    print('Invalid usage : Enter required account and username. If not found default is password')
    sys.exit()
if sys.argv[1] in pass_dict:
    if sys.argv[2] in pass_dict[sys.argv[1]]:
        pyperclip.copy(pass_dict[sys.argv[1]][sys.argv[2]])
        print("SUCCESS!")
        sys.exit()
    else:
        print('Username Not Found')
else:
    print('Account type not found')
pyperclip.copy('password')
#web_driver=selenium.webdriver.Firefox()

