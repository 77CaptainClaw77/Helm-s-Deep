import pyperclip,re
raw_data=pyperclip.paste()
phone_regex_mobile=re.compile(r'\d{10}')
phone_regex_landline=re.compile(r'\d+-\d+')
email_regex=re.compile(r'\S*@\S*')
phone_book_mobile = phone_regex_mobile.findall(raw_data)
phone_book_landline = phone_regex_landline.findall(raw_data)
email_book=email_regex.findall(raw_data)
print("The Landline Numbers Are:-")
for ph in phone_book_landline:
    print(ph)
print("The Mobile Numbers Are:-")
for ph in phone_book_mobile:
    print(ph)
print("The Email IDs Are:-")
for em in email_book:
    print(em)

