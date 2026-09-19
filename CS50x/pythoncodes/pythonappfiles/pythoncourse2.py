'''#quiz game

questions=("what is name of the first president of India?",
           "what is name of the first prime minister of India?",
           "what is name of the first education minister of India?")

options=(("A-nehru","B-indira gandhi","C-rajiv gandhi","D-rajendra prasad"),
         ("A-nehru","B-manmohan","C-bajpei","D-modi"),
         ("A-betu","B-pallu","C-jo hoga","D-kon hoga"))

answers=("D","A","C")
guesses=[]
score=0
question_num=0

for question in questions:
    print("--------------------")
    print(question)
    for option in options[question_num]:
        print(option)

    guess=input("Enter(A,B,C,D): ").upper()
    guesses.append(guess)
    if guess==answers[question_num]:
        score+=1
        print("CORRECT")
    else:
        print("INCORRECT")
        print(f"{answers[question_num]} is the correct answer")
    question_num+=1

print("answers: ",end=" ")
for answer in answers:
    print(answer,end=" ")
print()

print("guesses: ",end=" ")
for guess in guesses:
    print(guess,end=" ")
print()

score=int(score/len(questions)*100)
print(f"your score is:{score}%")

#dictionary
capitals={"usa":"washington dc","india":"delhi"}
print(dir(capitals))
print(help(capitals))
print(capitals.get("india"))

if  capitals.get("usa"):
    print("capital exists")
else:
    print("capitals doesn't exist")

capitals.update({"usa":"detriot"})
capitals.pop("india")
capitals.popitem()
capitals.clear()

keys=capitals.keys()
print(keys)
for key in capitals.keys():
    print(key)

values=capitals.values()
print(values)
for value in capitals.values():
    print(value)

items=capitals.items()
for key,value in capitals.items():
    print(f"{key}:{value}")'''

#concession stand program

menu={"pizza":3.00,
      "nachos":4.50,
      "popcorn":6.00,
      "fries":2.50,
      "chips":1.00,
      "pretzel":3.50,
      "soda":3.00,
      "lemonade":4.25}
cart=[]
total=0

print("--------MENU----------")
for key,value in menu.items():
    print(f"{key:10}:${value:.2f}")
print("-----------------------")

while True:
    food=input("select an item(q to quit): ")
    if food.lower()=="q":
        break
    elif menu.get(food) is not None:
        cart.append(food)
        
print("------YOUR ORDER--------")

for food in cart:
    total+=menu.get(food)
    print(food,end=" ")
    
print()
print(f"Total is :${total:.2f}")

#number guessing ------- print(help(random))

import random

number=random.randint(1,6)

options=("rock","scissors","paper")
option=random.choice(options)
print(option)

low=1
high=100
number=random.randint(low,high)

cards=["2","3","4","5","6","7","8","9","10","J","Q","K","A"]
random.shuffle(cards)
print(cards)

#number guess

import random
lowest_num=1
highest_num=100
answer=random.randint(lowest_num,highest_num)
guesses=0
is_running=True
print("python number guessing game")
print(f"select a number between {lowest_num} and {highest_num}")

while is_running:

    guess=input("enter your guess")

    if guess.isdigit():
        guess=int(guess)
        guesses+=1

        if guess<lowest_num or guess>highest_num:
            print("that number is out of range")
            print(f"please select a number between {lowest_num} and {highest_num}")
        elif guess<answer:
            print("too low! try again")
        elif guess>answer:
            print("too high! try again")
        else:
            print(f"CORRECT! the answer was {answer}")
            print(f"number of guesses: {guesses}")
            is_running=False
            
    else:
        print("invalid guess")
        print(f"please select a number between {lowest_num} and {highest_num}")

#rock paper scissors game
import random

options=("rock","paper","scissors")
running=True
while running:
    player=None
    computer=random.choice(options)
    
    while player not in options:
        player=input("enter a choice(rock,paper,scissors): ")
        
    print(f"Player: {player}")
    print(f"Computer: {computer}")

    if player==computer:
        print("Its a tie")
    elif player=="rock" and computer=="scissors":
        print("you win")
    elif player=="scissors" and computer=="paper":
        print("you win")
    elif player=="paper" and computer=="rock":
        print("you win")
    else:
        print("you lose")
    if not input("play again?(y/n): ").upper()=="y":
        running=False
print("thanks for playing")



        
        
        
        
    








 



    
    
        
    

    






      

 




    
        
