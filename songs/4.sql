from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows=db.execute("SELECT name FROM songs where danceability>0.75 and energy>0.75 and valence>0.75")

for row in rows:
    print(row["name"])
