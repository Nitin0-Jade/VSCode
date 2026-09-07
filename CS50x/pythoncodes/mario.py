while TRUE:
    height = int(input("Enter the height of the pyramid: "))
    if 1 <= height <= 8:
        break
    except ValueError:
        pass


for i in range(height):
    print(" "*(height-i-1) + "#"*(i+1) + "  " + "#"*(i+1))