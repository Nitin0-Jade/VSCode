from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows = db.execute("SELECT name FROM songs ORDER BY tempo DESC")

for row in rows:
    print(row["name"])

//all this files should be .py btw

