#Write a function Add_Item() to input ItemID, Name, and Price and store it in "MALL.CSV"
'''import csv
def Add_Item():
    ItemID = input("Enter ItemID: ")
    Name = input("Enter Name: ")
    Price = input("Enter Price: ")
    L = [ItemID, Name, Price]
    with open("MALL.CSV", "a", newline="") as f:
        write = csv.writer(f)
        write.writerow(L)
Add_Item()'''

#Write a function Search_Item(Name) to read "MALL.CSV" and display the price of the item if found
'''import csv
def Search_Item(Name):
    found=False
    with open("MALL.CSV","r") as f:
        reader=csv.reader(f)
        for row in reader:
            if row[1]==Name:
                print("price of item:",row[2])
                found=True
                break
    if not found:
        print("Record not found:")
Search_Item("raghav")'''

#Write a function Show_All() to read and display all records of "EMP.CSV" in a proper tabular format
'''import csv

def Show_All():
    with open("EMP.CSV", "r") as f:
        reader = csv.reader(f)
        for row in reader:
            for data in row:
                print(data, end="\t")
            print()

Show_All()'''

#Write a function Count_Delhi() to count how many employees in "USER.CSV" have their city as "Delhi"
'''import csv
def Count_Delhi():
    count=0
    with open("USER.CSV","r") as f:
        reader=csv.reader(f)
        for row in reader:
            if row[2]=="Delhi":
                count+=1
    print(count)
    return count
Count_Delhi()'''

#Write a function High_Price() to read "STOCK.CSV" and display names of products whose quantity is less than 10
'''import csv
def High_Price():
    with open("STOCK.CSV","r") as f:
        reader=csv.reader(f)
        for row in reader:
            if int(row[1])<10:
                print(row[2])
High_Price()'''

#Write a func Count_Dept(DName) to count how many employees in "COMPANY.CSV" belong to "Sales" dept
'''import csv
def Count_Dept(DName):
    count=0
    with open("COMPANY.CSV","r") as f:
        reader=csv.reader(f)
        for row in reader:
            if row[1]=="DName"
            count+=1
    print(count)
Count_Dept("Sales")'''

#Write a func Budget_Items() to read "GIFT.CSV" and display names of items with Price between 500 and 1000
'''import csv

def Budget_Items():
    with open("GIFT.CSV", "r") as f:
        reader = csv.reader(f)
        for row in reader:
            if 500 <= int(row[2]) <= 1000:
                print(row[1])

Budget_Items()'''               
        

    


            
















