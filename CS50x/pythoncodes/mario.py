while True:
    try:
        height = int(input("Enter the height of the pyramid: "))
        
    except ValueError:
        continue

    if 1 <= height <= 8:
        break

for i in range(height):
    print(" "*(height-i-1) + "#"*(i+1) + "  " + "#"*(i+1))