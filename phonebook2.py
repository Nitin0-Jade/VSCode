import csv


name= input("Enter name to search: ")
number = input("Enter number to search: ")

with open("phonebook.csv","a") as file:

    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
