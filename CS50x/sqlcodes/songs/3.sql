from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows=db.execute("SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5")

for row in rows:
    print(row["name"])
