''''#time counter
import time

def count(start,end):
    for x in range(start,end+1):
        print(x)
        time.sleep(1)
    print("DONE!")
count(0,10)

#*args=allows you to pass multiple non key argument

def display_name(*args):
    for arg in args:
        print(arg,end=" ")
display_name("Dr","ummm","yes","me")

#**kwargs=allows you to pass multiple keyword arguments,,,kwargs=dictionary
def print_address(**kwargs):
    for key,value in kwargs.items():
        print(f"{key}:{value}")

print_address(street="123",
              locality="idk",
              state="MU",
              code="21331")

#both args and kwargs
def shipping_label(*args,**kwargs):
    for arg in args:
        print(arg,end=" ")
    print()
    for value in kwargs.values():
        print(value,end=" ")
    if "apt" in kwargs:
        print(f"{kwargs.get('street')}{kwargs.get('state')}{kwargs.get('apt')}")
    else:
        print(f"{kwargs.get('state')}")
    

shipping_label("Dr","ummm","yes","me",
               street="123",
              locality="idk",
              state="MU",
              code="21331") 

#secret word guess(membership operators in,not in)

word="APPLE"
letter=input("guess a letter in the secret word: ")

if letter in word:
    print(f"{letter} was found in word")
else:
    print(f"{letter} was not found in word")

#list comprehension   = [expression for value in iterable if condition]
L=[]
for x in range(1,11):   #long cut
    L.append(x)
print(L)

doubles=[x*2 for x in range(1,11)]   # short cut
squares=[y*y for y in range(1,11)]

fruits=["apple","orange","banana","coconut"]
fruits=[fruit.upper() for fruit in fruits]
print(fruits)

fruits=[fruit[0] for fruit in ["apple","orange","banana","coconut"]]
print(fruits)

numbers=[1,2,3,-2,-5]
positive_nums=[num for num in numbers if num>=0]
negative_nums=[num for num in numbers if num<=0]
print(positive_nums)

#match case statement(switch): An alternative to using many 'elif' statements
#                                                 execute some code if a value matches a 'case'
#                                                 Benefits: cleaner and syntax is more readable

def day_of_week(day):
    if day==1:
        return "it is sunday"
    elif day==2:
        return "it is monday"
    elif day==3:
        return "it is tuesday"
    elif day==4:
        return "it is wednesday"
    elif day==5:
        return "it is thursday"
    elif day==6:
        return "it is friday"
    elif day==7:
        return "it is saturday"
    else:
        return "Not a valid day"
print(day_of_week(2))

def day_of_week(day):
    match day:
        case 1:       # if,elif
            return "it is sunday"
        case 2:
            return "it is monday"
        case 3:
            return "it is tuesday"
        case 4:
            return "it is wednesday"
        case 5:
            return "it is thursday"
        case 6:
            return "it is friday"
        case 7:
            return "it is saturday"
        case _:             # else,wildcard case
            return "Not a valid day"
print(day_of_week(2))


def is_weekend(day):
    match day:
        case "saturday"| "sunday":
            return True
        case "monday"|"tuesday"|"wednesday"|"thursday"|"friday":
            return False
        case _:
            return False
print(is_weekend("friday"))

#modules
print(help("modules"))
from math import e
print(help("math"))
#importing from other python files(example.py)
import example

result=example.pi
result1=example.area(10)
result2=example.circumference(10)
result3=example.square(5)
print(result3)

#variable scope=where a variable is visible and accessible
#scope resolution=(LEGB) local->enclosed->global->built in

#local->
def func1():
    x=1
    print(x)
func1()

def func2():
    x=2
    print(x)
func2()

#enclosed->
def func1():
    x=1
    def func2():                    #Tab for indenting
        x=2
        print(x)
    func2()
    
func1()

#golbal->
def func1():
    print(x)

def func2():
    print(x)
x=3
func1()
func2()

#built in->
from math import e
 def func1():
     print(e)'''

#if __name__==__main__: (this script can be impoerted OR run standalone)
#                                        functions and classes in this module can be reused
#                                        without the main block of code executing

def main():
    
     
    






    

















    









    

    




