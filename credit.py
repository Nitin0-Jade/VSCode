import sys

card = int(input("Enter Card Details: "))

temp_card = card

length=0

while temp_card>0 :
    temp_card //=10
    length +=1

if length!=13 and length!=15 and length!=16 :
    print(f"INVALID")
    sys.exit()

sum1=0
sum2=0
position=0
temp_card = card

while temp_card>0:
    digit = temp_card%10

    if position%2 ==0:
        sum2+=digit
    else:
        product=digit*2
        sum1+= product//10 + product%10
    
    temp_card //= 10
    position +=1

total_sum= sum1+sum2

if total_sum %10 != 0:
    print(f"INVALID")
    sys.exit()

starting_digits = card
while starting_digits >= 100 :
    starting_digits //=10

#for AMEX
if length == 15 and (starting_digits == 34 or starting_digits == 37):    
    print("AMEX")

# MASTERCARD: 16 digits, starts with 51, 52, 53, 54, or 55
elif length == 16 and (starting_digits >= 51 and starting_digits <= 55):
    print("MASTERCARD")

# VISA: 13 or 16 digits, starts with 4 (so start_digits / 10 is 4)
elif (length == 13 or length == 16) and (starting_digits // 10 == 4):
    print("VISA")

else:
    print("INVALID")

sys.exit()