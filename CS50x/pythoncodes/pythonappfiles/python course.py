#calculator program
operator=input("enter an operator(+ - * / ): ")
num1=float(input("enter the 1st number"))
num2=float(input("enter the 2nd number"))

if operator=='+':
    result=num1+num2
    print(round(result,2))
elif operator=='-':
    result=num1-num2
    print(round(result,2))
elif operator=='*':
    result=num1*num2
    print(round(result,2))
elif operator=='/':
    result=num1/num2
    print(round(result,2))
else:
    print("operator is not valid")

#weight converter
weight=float(input("enter the weight : "))
unit=input("kilograms or pounds?(K or L) : ")

if unit=="K":
    weight*=2.205
    unit="Lbs"
elif unit=="L":
    weight/=2.205
    unit="Kgs"
else:
    print("unit was not valid")

print("your weight is:",round(weight),unit)

#useful funcs
name=input("enter your full name: ")
print(name.find("N"))
print(name.rfind('n'))
print(len(name))
print(name.capitalize())
print(name.upper())
print(name.isdigit())
print(name.count("-"))
name=name.replace("-"," ")
print(name)
#in one line
print(help(str))

#password creation
password=input("enter the password: ")
if len(password)>12:
     print("your password is not correct")
elif not password.find(" ")== -1:
     print("your password can't contain spaces")
elif not password.isalpha():
     print("your password can't contain numbers")
else:
    print("password is correct")

#compound interest program
principle=0
rate=0
time=0

while principle<=0:
    principle=float(input("enter the principle amount"))
    if principle<=0:
        print("principle can't be less than or equal to zero")
while rate<=0:
    rate=float(input("enter the intrest rate"))
    if rate<=0:
        print("rate can't be less than or equal to zero")
while True:
    time=float(input("enter the time"))
    if time<=0:
        print("time can't be less than or equal to zero")
    else:
        break
    
total=principle*pow((1+rate/100),time)
print("balance is",total)

#cooldown timer
import time

my_time=int(input("enter the time in seconds: "))

for x in range(my_time,0,-1):
    seconds=x%60
    minutes=int(x/60)%60
    hours=int(x/3600)
    print(f"{hours:02}:{minutes:02}:{seconds:02}")
    time.sleep(1)
print("TIME'S UP")

#nested loop
for x in range(3):
    for y in range(1,11):
        print(y,end=" ")
    print(x)

#nested loop
rows=int(input("enter the no. of rows"))
columns=int(input("enter the no. of columns"))
symbol=int(input("enter the symbol to use:"))

for  x in range(rows):
    for y in range(columns):
        print(symbol,end=" ")
    print()

#imp
list1=[1,2,3,4,5]
print(dir(list1))
print(help(list1))
print("2" in list1)
list1[0]=7
list1.append(9)
list1.remove(1)
list1.insert(0,"2")
list1.sort()
list1.reverse()
list1.clear()
print(list1.index("2"))
list1.count("1")

#shopping cart
foods=[]
prices=[]
total=0

while True:
    food=input("enter a food to buy(q to quit): ")
    if food.lower()=="q":
        break
    else:
        price=float(input(f"enter the price of a {food}:$"))
        foods.append(food)
        prices.append(price)
print("-----YOUR CART-----")

for food in foods:
    print(food,end=" ")
for price in prices:
    total+=price
print(f"your total is:${total}")

#2D collection

num_pad=((1,2,3),
         (4,5,6),
         (7,8,9))
for row in num_pad:
    for num in row:
        print(num,end=" ")
    print()

         


     

      

    
        


    
 

 
        

    
    
    
    
    







    
    
    
