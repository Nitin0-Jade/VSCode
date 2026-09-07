from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows=db.execute("SELECT AVG(energy) FROM songs")

row = rows[0]

print(row["energy"])
