#Write a function Add_Student() to take RollNo, Name and store them as a list in "STUDENT.DAT"
'''import pickle
def Add_Student():
    RollNo=input("enter roll no. :")
    Name=input("enter Name :")
    L=[RollNo,Name]
    with open("STUDENT.DAT","ab") as f:
        pickle.dump(L,f)
Add_Student()'''

#Write a function Search_Roll(R) to search for a specific Roll Number in "STUDENT.DAT" and display the name; else show "Not Found"
'''import pickle

def Search_Roll(R):
    found = False
    with open("STUDENT.DAT", "rb") as f:
        while True:
            try:
                rec = pickle.load(f)
                if rec[0] == R:
                    print("Name =", rec[1])
                    found = True
                    break
            except EOFError:
                break
    if found == False:
        print("Not Found")'''

#Write a function Update_Marks(R, NewM) to search for RollNo R and update their marks to NewM in the binary file
'''import pickle

def Update_Marks(R, NewM):
    data = []
    with open("STUDENT.DAT", "rb") as f:
        while True:
            try:
                rec = pickle.load(f)
                if rec[0] == R:
                    rec[2] = NewM
                data.append(rec)
            except EOFError:
                break

    with open("STUDENT.DAT", "wb") as f:
        for rec in data:
            pickle.dump(rec, f) '''

#Write a function Transfer_Records() to copy all records from "STAFF.DAT" to "MEMBERS.DAT" where salary is > 50000
'''import pickle

def Transfer_Records():
    L = []
    with open("STAFF.DAT", "rb") as f:
        while True:
            try:
                record = pickle.load(f)
                if record[2] > 50000:
                    L.append(record)
            except EOFError:
                break

    with open("MEMBERS.DAT", "wb") as f:
        for record in L:
            pickle.dump(record, f)'''

#Write a func Revise_Price(ID, NewP) to find Product ID in "SHOP.DAT" and update its Price to NewP
 '''import pickle

def Revise_Price(ID, NewP):
    L = []
    found = False
    with open("SHOP.DAT", "rb") as f:
        while True:
            try:
                rec = pickle.load(f)
                if rec[0] == ID:
                    rec[2] = NewP
                    found = True
                L.append(rec)
            except EOFError:
                break

    with open("SHOP.DAT", "wb") as f:
        for rec in L:
            pickle.dump(rec, f)

    if found == True:
        print("Price Updated")
    else:
        print("Record Not Found")'''

 #Write a func Update_Sal(ID, Bonus) to find Employee ID in "EMP.DAT" and add the Bonus amount to their existing Salary.
'''import pickle

def Update_Sal(ID,Bonus):
    L=[]
    found=False
    with open("EMP.DAT","rb") as f:
        while True:
            try:
                record=pickle.load(f)
                if record[0]==ID:
                    record[2]+=Bonus
                    found=True
                L.append(record)
            except EOFError:
                break
    with open("EMP.DAT", "wb") as f:
        for record in L:
            pickle.dump(record, f)
    if found==True:
        print("salary updated")
    else:
        print("record not found")'''

#Write a func Copy_Fresh() to copy records from "FRUITS.DAT" to "FRESH.DAT" where the ExpiryDate is in '2025'             
'''import pickle

def Copy_Fresh():
    found = False
    with open("FRUITS.DAT", "rb") as infile, open("FRESH.DAT", "wb") as outfile:
        while True:
            try:
                rec = pickle.load(infile)
                if "2025" in rec[2]:
                    pickle.dump(rec, outfile)
                    found = True
            except EOFError:
                break

    if found:
        print("Records copied")
    else:
        print("No record found")'''
