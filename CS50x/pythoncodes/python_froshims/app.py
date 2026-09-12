from cs50 import SQL
from flask import Flask,render_template,request,redirect

app=Flask(__name__)

db=SQL("sqlite:///froshims.db")

SPORTS=[
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]


@app.route("/")
def index(): 
    return render_template("index.html",sport=SPORTS)

@app.route("/deregister",methods=["POST"])
def deregister():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?",id)
    return redirect("/registrants")



@app.route("/register",methods=["POST"])
def register():
    
    #validate name
    name= request.form.get("name")
    if not name:
        return render_templates("error.html",message="Missing-Name")

    #validate sport
    sports= request.form.getlist("sport")
    if not sports:
        return render_templates("error.html",message="Missing-sports")
    for sport in sports:
        if sport not in SPORTS:
            return render_templates("error.html",message="Invalid sport")

    #Remember student
    for sport in sports:
        db.execute("INSERT INTO registrants (name,sport) VALUES(?,?)",name,sport)

    #confirmed
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants=db.execute("SELECT * FROM registrants")
    return render_templates("registrants.html",registrants=registrants)


