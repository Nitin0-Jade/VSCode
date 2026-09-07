from cs50 import SQL

db = SQL("sqlite:///songs.db")

rows = db.execute("SELECT name FROM songs where artist_id= (SELECT id FROM artists where name = 'Post Malone') ")

for row in rows:
    print(row["name"])
