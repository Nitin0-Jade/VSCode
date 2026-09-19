#Write a function Change(List, N) where even positions are multiplied by 2 and odd positons are incremented by 5
'''def Change(L):
    for i in range(len(L)):
        if i%2==0:
            L[i]*=2
        else:
            L[i]+=5
    return L
print(Change([12,15,20,60]))'''


#Write a function Count_HV(S) to count and display the number of Uppercase Vowels and Digits in a string S.
'''def Count_HV(S):
    v = 0
    d = 0
    
    for ch in S:
        if ch in "AEIOU":
            v += 1
        elif ch.isdigit():
            d += 1
    
    print("Uppercase Vowels:", v)
    print("Digits:", d)

a = "Hmm Very IntResting 123"
Count_HV(a)'''

#Write a function Calculate(P, R=7.5, T=2) to calculate and return Simple Interest.
'''def Calculate(P,R=7.5,T=2):
    c=P*R*T//100
    return c
print(Calculate(100))'''

#Write a function Filter_Long(Names) that takes a list of names and returns a new list containing names with more than 5 characters
'''def Filter_Long(Names):
    stk=[]
    for i in Names:
            if len(i)>5:
                stk.append(i)
    return stk
lst=["names","lol","dumber"]
print(Filter_Long(lst))'''

#Create a function Show_Profile(Name, Age, City) and demonstrate calling it using keyword arguments in different orders.
'''def Show_Profile(Name,Age,City):
    return Name,Age,City 
print(Show_Profile("umm",12,"oluty"))'''

#Write a func Change_Val(L) where elements divisible by 5 are replaced by their square, and others are incremented by 10
'''def Change_Val(L):
    for i in range(len(L)):
        if L[i] % 5 == 0:
            L[i] = L[i] ** 2   
        else:
            L[i] += 10
    return L

print(Change_Val([15,4,6,7,10]))'''

#Write a func Count_Alpha(S) to count and display total number of Lowercase vowels and Special characters in string S
'''def Count_Alpha(S):
    v = 0   # lowercase vowels
    sp = 0  # special characters
    
    for ch in S:
        if ch in "aeiou":
            v += 1
        elif not ch.isalnum() and ch != " ":
            sp += 1
    
    print("Lowercase vowels:", v)
    print("Special characters:", sp)

print(Count_Alpha("alpha lol hmm!@#"))'''

#Write a func Get_Short(Names) that returns a new list of names that have exactly 4 characters
'''def Get_Short(Names):
    stk=[]
    for i in Names:
            if len(i)==4:
                stk.append(i)
    return stk
print(Get_Short(["lol","what", "is","this","code"]))'''

#Write a func Half_or_Double(L) where even numbers are divided by 2 and odd numbers are multiplied by 2
'''def Half_or_Double(L):
    l=[]
    for i in L:
        if i%2==0:
            i=i/2
        else:
            i*=2
        l.append(i)
    return l
print(Half_or_Double([12,2,3,1,4,5]))'''

#Write a func Check_Case(S) to count and display the total number of Uppercase alphabets and Digits in string S
'''def Check_Case(S):
    digits = 0
    upper = 0
    for i in S:
        if i.isdigit():
         digits +=1
        elif i.isupper():
         upper +=1
    print("digits are:",digits )
    print("uppercase are:",upper )
print(Check_Case("All is well 1224"))'''

#Write a func Long_Names(List) that returns a new list containing names that start with the letter 'S' and have more than 5 characters
'''def Long_Names(List):
    L=[]
    for i in List:
        if len(i)>5 and i[0]=="S":
            L.append(i)
    return L
print(Long_Names(["Smurfing","tako","Swimming"]))'''

#stack program
'''stack = []

n = int(input("Enter number of elements: "))
for i in range(n):
    item = int(input("Enter element: "))
    stack.append(item)

print("Stack elements:", stack)

print("Odd numbers in stack:")
while stack:
    x = stack.pop()
    if x % 2 != 0:
        print(x)'''

#csv hospital management que
'''import csv

def add_patient():
    with open("patients.csv", "a", newline="") as file:
        writer = csv.writer(file)
        pid = input("Enter Patient ID: ")
        name = input("Enter Patient Name: ")
        age = input("Enter Age: ")
        disease = input("Enter Disease: ")
        writer.writerow([pid, name, age, disease])
    print("Patient record added successfully")

def view_patient():
    try:
        with open("patients.csv", "r") as file:
            reader = csv.reader(file)
            print("\nPatient Records:")
            for row in reader:
                print(row)
    except FileNotFoundError:
        print("No records found")

while True:
    print("\nHOSPITAL MANAGEMENT SYSTEM")
    print("1. Add Patient")
    print("2. View Patient")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        add_patient()
    elif choice == '2':
        view_patient()
    elif choice == '3':
        print("Thank you for using the system")
        break
    else:
        print("Invalid choice. Please try again.")'''

#csv que 2
'''import csv
with open("students.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["Roll No", "Name", "Class", "Marks"])

    n = int(input("Enter number of students: "))

    for i in range(n):
        print("Enter details of student", i+1)
        roll = input("Roll No: ")
        name = input("Name: ")
        clas = input("Class: ")
        marks = input("Marks: ")

        writer.writerow([roll, name, clas, marks])

print("Student data stored successfully in students.csv")

import csv

with open("students.csv", "r") as file:
    reader = csv.reader(file)

    print("Student Records:\n")
    for row in reader:
        print(row)'''

#palindrome que
'''string = input("Enter a string: ")
length = len(string)
rev = length - 1
flag = True

for i in range(length // 2):
    if string[i] != string[rev]:
        flag = False
        break
    rev -= 1
if flag:
    print(string, "is a palindrome")
else:
    print(string, "is not a palindrome")'''

#module que
'''import mymodule

x = int(input("Enter first number: "))
y = int(input("Enter second number: "))

print("Addition:", mymodule.add(x, y))
print("Subtraction:", mymodule.sub(x, y))'''

#binary que
'''import pickle
with open("students.dat", "wb") as file:
    n = int(input("Enter number of students: "))

    for i in range(n):
        print("Enter details of student", i + 1)
        roll = int(input("Roll No: "))
        name = input("Name: ")
        clas = input("Class: ")
        marks = float(input("Marks: "))

        student = [roll, name, clas, marks]
        pickle.dump(student, file)

print("Student data stored successfully in binary file")

import pickle

try:
    with open("students.dat", "rb") as file:
        print("Student Records:\n")

        while True:
            student = pickle.load(file)
            print("Roll No:", student[0])
            print("Name:", student[1])
            print("Class:", student[2])
            print("Marks:", student[3])
            print("-" * 20)

except EOFError:
    print("End of file reached")'''



            
            

        
            
        
    

    

    

