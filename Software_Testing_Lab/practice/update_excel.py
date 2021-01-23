import openpyxl as xl
import os
if os.path.exists("StudentSheet.xlsx"):
    wb=xl.load_workbook("StudentSheet.xlsx")
    ws=wb.worksheets[0]
else:
    print("File Not Found! Creating new file")
    wb=xl.Workbook("StudentSheet.xlsx")
    ws=wb.active()
    ws.append(["Name","USN","Marks 1","Marks 2","Marks 3"])
n=int(input("Enter the number of records to be updated: "))
for i in range(n):
    name=input("Enter Name: ")
    usn=input("Enter USN: ")
    marks=input("Enter marks in 3 subjects: ").split()
    ws.append([name,usn,marks[0],marks[1],marks[2]])
wb.save("StudentSheet.xlsx")
