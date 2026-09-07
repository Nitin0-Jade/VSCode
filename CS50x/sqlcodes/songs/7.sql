from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows=db.execute("SELECT AVG(energy) FROM songs where artist_id = (SELECT id FROM artists where name='Drake')")

for row in rows:
    print(row["name"])
