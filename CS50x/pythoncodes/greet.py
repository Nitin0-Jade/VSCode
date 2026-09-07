from sys import argv

#argv excludes python script name
if len(argv) == 2:
    name = argv[1]
    print(f"Hello, {name}!")
else:
    print("Hello, World!")
