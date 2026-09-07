from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows=db.execute("'SELECT name FROM songs where name LIKE '%feat.%'")

for row in rows:
    print(row["name"])
