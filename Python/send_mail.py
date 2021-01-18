import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import getpass
import sys
print("Note: Please enable allow less secure apps on gmail in order to use this program.")
mail_server=smtplib.SMTP('smtp.gmail.com',587)
mail_server.starttls()
email_id=input("Enter mail id: ")
password=getpass.getpass("Enter password: ")
mail_server.login(email_id,password)
email_mesg=MIMEMultipart()
email_mesg['From']=email_id
email_mesg['To']=input("Enter reciever mail address: ")
email_mesg['Subject']=input("Enter the subject of the mail: ")
print("Enter the contents of the mail(Press Ctrl-D to stop):")
content=''.join(sys.stdin.readlines())
email_mesg.attach(MIMEText(content,'plain','utf-8'))
mail_server.send_message(email_mesg)
mail_server.quit()
