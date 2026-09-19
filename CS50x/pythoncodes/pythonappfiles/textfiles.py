#Write a function Count_Words() to read "STORY.TXT" and count how many times the word "the" or "this" appears (case insensitive)
'''def Count_Words():
    count = 0
    with open("STORY.TXT", "r") as f:
        data = f.read().lower().split()
        
        for word in data:
            if word == "the" or word == "this":
                count += 1
                
    print("Count =", count)'''

#Write a function Show_Lines() to display lines from "NOTES.TXT" that start with the alphabet 'A' or 'E'
'''def Show_Lines():
    with open("NOTES.TXT","r") as f:
        data=f.readlines()
        for word in data:
            if word[0]=="A"or word[0]=="E":
                print(word)
Show_Lines()'''
#M2
'''def Show_Lines():
    with open("NOTES.TXT", "r") as f:
        for line in f:
            if line.startswith("A") or line.startswith("E"):
                print(line)

Show_Lines()'''

#Write a function Count_Upper() to count total number of Uppercase alphabets in a file "DATA.TXT"
'''def Count_Upper():
    count=0
    with open("DATA.TXT","r") as f:
        data=f.read()
        for word in data:
            if word.isupper()==True:
                count+=1
    print(count)
Count_Upper()'''

#Write a function Long_Words() to display all words from "INFO.TXT" which have more than 4 characters
'''def Long_Words():
    with open("INFO.TXT","r") as f:
        data=f.read().split()
        for word in data:
            if len(word)>4:
                print(word)
Long_Words()'''

#Write a function Copy_Data() to copy all lines from "ORIGINAL.TXT" to "BACKUP.TXT" that do not contain the character '2'
'''def Copy_Data():
    L = []
    with open("ORIGINAL.TXT", "r") as infile, open("BACKUP.TXT", "w") as outfile:
        for line in infile:
            if '2' not in line:
                L.append(line)
        outfile.writelines(L)

Copy_Data()'''
#M-2
'''def Copy_Data():
    with open("ORIGINAL.TXT", "r") as infile, open("BACKUP.TXT", "w") as outfile:
        for line in infile:
            if '2' not in line:
                outfile.write(line)

Copy_Data()'''

#Write a func Search_Word() to read "MESSAGE.TXT" and count how many times words "is" or "are" appear
'''def Search_Word():
    count=0
    with open("MESSAGE.TXT","r") as f:
        data=f.read().split()
        for word in data:
            if word=="is" or word=="are":
                count+=1
        print(count)
Search_Word()'''

#Write a func Start_Digit() to display all lines from "STORY.TXT" that start with a number (0-9)
'''def Start_Digit():
    with open("STORY.TXT","r") as f:
        data=f.readlines()
        for word in data:
            if word[0].isdigit():
                print(word)
Start_Digit()'''

#Write a func Total_Vowels() to count total number of vowels (A, E, I, O, U) in "REPORT.TXT"
'''def Total_Vowels():
    count=0
    with open("REPORT.TXT","r") as f:
        data=f.read().split()
        for word in data:
            if word=="A,E,I,O,U":
                count+=1
    print(count)
Total_Vowels()'''

#Write a func Small_Words() to print all words from "PARA.TXT" whose length is less than 3
'''def Small_Words():
    with open("PARA.TXT","r") as f:
        data=f.read().split()
        for word in data:
            if len(word)<3:
                print(word)
Small_Words()'''

#Write a func Move_Lines() to copy all lines from "LOG.TXT" to "ERROR.TXT" that contain the word "Error"
'''def Move_Lines():
    L=[]
    with open ("LOG.TXT","r") as infile, open("ERROR.TXT","w") as outfile:
        for line in infile:
            if "Error" in line:
                L.append(line)
                outfile.readlines(L)
Move_Lines()'''

#Write a func Count_The_An() to read "STORY.TXT" and count the occurrences of words "the" and "an"
'''def Count_The_An():
    count=0
    with open("STORY.TXT","r") as f:
        data=f.read().split()
        for line in data:
            if word.lower()=="the" or word.lower()=="an"
                count+=1
    print(count)
Count_The_An()'''

#Write a func Ending_With_S() to display all lines from "NOTES.TXT" that end with the character 's' or 'S'
'''def Ending_With_S():
    with open("NOTES.TXT","r") as f:
        data=f.readlines()
        for line in data:
            if line.rstrip().endswith("S") or line.rstrip().endswith("s")
                print(line)
Ending_With_S()'''

#Write a func Total_Consonants() to count the total number of consonants in "DATA.TXT
'''def Total_Consonants():
    count=0
    with open("DATA.TXT","r") as f:
        data=f.read().split()
        for ch in data:
            if ch.isalpha() and ch.lower() not in "aeiou":
                count+=1
    print(count)            
Total_Consonants()'''

            
        
        
            
            
        

        
        
        
        

            
    

    
