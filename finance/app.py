import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    username=request.form.get("username")
    user_id=session["user_id"]
    rows=db.execute("SELECT symbol, SUM(shares) AS total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0",user_id)
    holdings = []
    grand_total = 0

    for row in rows:
        stock = lookup(row["symbol"])
        total_shares = row["total_shares"]
        total_price = total_shares * stock["price"]

        holdings.append({
            "symbol": row["symbol"],
            "shares": total_shares,
            "price": stock["price"],
            "total": total_price
        })

        grand_total += total_price

    # Get user's cash
    cash = db.execute(
        "SELECT cash FROM users WHERE id = ?",
        user_id
    )[0]["cash"]

    grand_total += cash

    return render_template(
        "index.html",
        holdings=holdings,
        cash=cash,
        grand_total=grand_total
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Make sure symbol was entered
        if not symbol:
            return apology("must provide symbol", 400)

        # Look up stock
        stock = lookup(symbol)

        if stock is None:
            return apology("invalid symbol", 400)

        # Make sure shares is a positive integer
        try:
            shares = int(shares)
        except (TypeError, ValueError):
            return apology("shares must be a positive integer", 400)

        if shares <= 0:
            return apology("shares must be a positive integer", 400)

        price = stock["price"]
        total_cost = price * shares

        user_id = session["user_id"]

        # Get user's cash
        balance = db.execute(
            "SELECT cash FROM users WHERE id = ?",
            user_id
        )[0]["cash"]

        # Make sure user can afford it
        if balance < total_cost:
            return apology("can't afford", 400)

        # Remove money
        db.execute(
            "UPDATE users SET cash = cash - ? WHERE id = ?",
            total_cost,
            user_id
        )

        # Record transaction
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) "
            "VALUES (?, ?, ?, ?)",
            user_id,
            stock["symbol"],
            shares,
            price
        )

        return redirect("/")

    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transaction_ig = db.execute("SELECT * FROM TRANSACTIONS WHERE user_id=?")
    return render_template("history.html",transactions=transaction_ig)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol=request.form.get("symbol")
        if lookup(symbol) == None:
            return apology("INVALID SYMBOL",404)
        return render_template("index.html",quote=lookup(symbol))
    else:
        return render_template("quote.html")
    return apology("ERROR lol")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            return apology("must provide username", 403)
        elif not password:
            return apology("must provide password", 403)
        elif not confirmation:
            return apology("must provide confirmation", 403)
        elif password != confirmation:
            return apology("passwords must match", 403)

        existing = db.execute("SELECT * FROM users WHERE username = ?", username)
        if existing:
            return apology("username already exists", 400)

        hashed = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed)

        new_user = db.execute("SELECT id FROM users WHERE username = ?", username)
        session["user_id"] = new_user[0]["id"]

        return redirect("/")

    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":

        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Check symbol
        if not symbol:
            return apology("must provide symbol", 400)

        stock = lookup(symbol)

        if stock is None:
            return apology("invalid symbol", 400)

        # Check shares
        try:
            shares = int(shares)
        except (TypeError, ValueError):
            return apology("shares must be a positive integer", 400)

        if shares <= 0:
            return apology("shares must be a positive integer", 400)

        user_id = session["user_id"]

        # Find how many shares the user owns
        owned = db.execute(
            "SELECT SUM(shares) AS total_shares "
            "FROM transactions "
            "WHERE user_id = ? AND symbol = ?",
            user_id,
            stock["symbol"]
        )[0]["total_shares"]

        # User doesn't own enough
        if owned is None or owned < shares:
            return apology("not enough shares", 400)

        price = stock["price"]
        total_price = price * shares

        # Add money to cash
        db.execute(
            "UPDATE users SET cash = cash + ? WHERE id = ?",
            total_price,
            user_id
        )

        # Record sale as negative shares
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) "
            "VALUES (?, ?, ?, ?)",
            user_id,
            stock["symbol"],
            -shares,
            price
        )

        return redirect("/")

    else:
        return render_template("sell.html")

    

