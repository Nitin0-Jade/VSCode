import csv

with open("favoraits.csv", "r") as file:
    
    reader= csv.DictReader(file)

    counts={}

    for row in reader:
        favorite=row["language "]
        if favorite not in counts:
            counts[favorite]=1 //becuz atating me 
            //counts nhi define h so garbage value h 
            //matlab key hi nhi to value kha jaye 
            //so key ko initialize kra
        counts[favorite]+=1

for favorite in counts:
    print(favorite,counts[favorite])