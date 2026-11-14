Summary

Inheritance allows us to model an is-a relationship between two objects. The object being inherited from is called the parent class, base class, or superclass. The object doing the inheriting is called the child class, derived class, or subclass.

When a derived class inherits from a base class, the derived class acquires all of the members of the base class.

When a derived class is constructed, the base portion of the class is constructed first, and then the derived portion is constructed. In more detail:

Memory for the derived class is set aside (enough for both the base and derived portions).
The appropriate derived class constructor is called.
The base class object is constructed first using the appropriate base class constructor. If no base class constructor is specified, the default constructor will be used.
The initialization list of the derived class initializes members of the derived class.
The body of the derived class constructor executes.
Control is returned to the caller.
Destruction happens in the opposite order, from most-derived to most-base class.

C++ has 3 access specifiers: public, private, and protected. The protected access specifier allows the class the member belongs to, friends, and derived classes to access protected members, but not the public.

Classes can inherit from another class publicly, privately, or protectedly. Classes almost always inherit publicly.

Here’s a table of all of the access specifier and inheritance types combinations:

Access specifier in base class	Access specifier when inherited publicly	Access specifier when inherited privately	Access specifier when inherited protectedly
Public	Public	Private	Protected
Private	Inaccessible	Inaccessible	Inaccessible
Protected	Protected	Private	Protected
Derived classes can add new functions, change the way functions that exist in the base class work in the derived class, change an inherited member’s access level, or hide functionality.

Multiple inheritance enables a derived class to inherit members from more than one parent. You should generally avoid multiple inheritance unless alternatives lead to more complexity.

Quiz time

Question #1

For each of the following programs, determine what they output, or if they would not compile, indicate why. This exercise is meant to be done by inspection, so do not compile these (otherwise the answers are trivial).

a)

#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}
};

class Derived: public Base
{
public:
	Derived()
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}
};

int main()
{
	Derived d;

	return 0;
}
Hide Solution

Construction happens in order from most-Parent to most-Child. Destruction happens in the opposite order.

Base()
Derived()
~Derived()
~Base()
b)

#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}
};

class Derived: public Base
{
public:
	Derived()
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}
};

int main()
{
	Derived d;
	Base b;

	return 0;
}
Hint: Local variables are destroyed in the opposite order of definition.

Hide Solution

First we construct d, which prints:

Base()
Derived()
Then we construct b, which prints:

Base()
Then we destruct b, which prints:

~Base()
Then we destruct d, which prints:

~Derived()
~Base()
c)

#include <iostream>

class Base
{
private:
	int m_x {};
public:
	Base(int x): m_x{ x }
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() const { std::cout << "Base: " << m_x << '\n';  }
};

class Derived: public Base
{
public:
	Derived(int y):  Base{ y }
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() const { std::cout << "Derived: " << m_x << '\n'; }
};

int main()
{
	Derived d{ 5 };
	d.print();

	return 0;
}
Hide Solution

Doesn’t compile, Derived::print() can’t access private member m_x

d)

#include <iostream>

class Base
{
protected:
	int m_x {};
public:
	Base(int x): m_x{ x }
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() const { std::cout << "Base: " << m_x << '\n';  }
};

class Derived: public Base
{
public:
	Derived(int y):  Base{ y }
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() const { std::cout << "Derived: " << m_x << '\n'; }
};

int main()
{
	Derived d{ 5 };
	d.print();

	return 0;
}
Hide Solution

Base()
Derived()
Derived: 5
~Derived()
~Base()
e)

#include <iostream>

class Base
{
protected:
	int m_x {};
public:
	Base(int x): m_x{ x }
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() const { std::cout << "Base: " << m_x << '\n';  }
};

class Derived: public Base
{
public:
	Derived(int y):  Base{ y }
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() const { std::cout << "Derived: " << m_x << '\n'; }
};

class D2 : public Derived
{
public:
	D2(int z): Derived{ z }
	{
		std::cout << "D2()\n";
	}
	~D2()
	{
		std::cout << "~D2()\n";
	}

        // note: no print() function here
};

int main()
{
	D2 d{ 5 };
	d.print();

	return 0;
}
Hide Solution

Base()
Derived()
D2()
Derived: 5
~D2()
~Derived()
~Base()

/////



#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string_view name, std::string_view color)
		: m_name{ name }, m_color{ color }
	{
	}

	const std::string& getName() const { return m_name; }
	const std::string& getColor() const { return m_color; }
};

class Apple: public Fruit
{
// The previous constructor we used for Apple had a fixed name ("apple").
// We need a new constructor for GrannySmith to use to set the name of the fruit
protected: // protected so only derived classes can access
	Apple(std::string_view name, std::string_view color)
		: Fruit{ name, color }
	{
	}

public:
	Apple(std::string_view color="red")
		: Fruit{ "apple", color }
	{
	}
};

class Banana : public Fruit
{
public:
	Banana()
		: Fruit{ "banana", "yellow" }
	{
	}
};

class GrannySmith : public Apple
{
public:
	GrannySmith()
		: Apple{ "granny smith apple", "green" }
	{
	}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}




////



#include "Random.h" // https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

class Potion
{
public:
    // All possible types of potions
    enum Type
    {
        health,
        strength,
        poison,

        // For random potion generation
        max_type
    };

    enum Size
    {
        small,
        medium,
        large,

        max_size
    };


private:
    Type m_type{};
    Size m_size{};

public:
    Potion(Type type, Size size)
        : m_type{ type },
        m_size{ size }
    {
    }

    Type getType() const { return m_type; }
    Size getSize() const { return m_size; }

    // The names of potions are compile-time literals, we can
    // return a std::string_view.
    static std::string_view getPotionTypeName(Type type)
    {
        static constexpr std::string_view names[] {
          "Health",
          "Strength",
          "Poison"
        };

        return names[type];
    }

    static std::string_view getPotionSizeName(Size size)
    {
        static constexpr std::string_view names[] {
          "Small",
          "Medium",
          "Large"
        };

        return names[size];
    }

    std::string getName() const
    {
        // We use a std::stringstream, but this could also be solved using
        // std::string.
        // We first used std::stringstream in lesson 7.13.
        std::stringstream result{};

        result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());

        // We can extract the string from an std::stringstream by using the str()
        // member function.
        return result.str();
    }

    static Potion getRandomPotion()
    {
        return Potion{
          static_cast<Type>(Random::get(0, max_type - 1)),
          static_cast<Size>(Random::get(0, max_size - 1))
        };
    }
};

class Creature
{
protected:
    std::string m_name;
    char m_symbol {};
    int m_health {};
    int m_damage {};
    int m_gold {};

public:
     Creature(std::string_view name, char symbol, int health, int damage, int gold)
        : m_name{ name }
        , m_symbol{ symbol }
        , m_health{ health }
        , m_damage{ damage }
        , m_gold{ gold }
    { }

    char getSymbol() const { return m_symbol; }
    const std::string& getName() const { return m_name; }
    bool isDead() const { return m_health <= 0; }
    int getGold() const { return m_gold; }
    void addGold(int gold) { m_gold += gold; }
    void reduceHealth(int health) { m_health -= health; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
};

class Player : public Creature
{
    int m_level{ 1 };

public:
    Player(const std::string& name)
        : Creature{ name, '@', 10, 1, 0 }
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    // Applies a potion's effect to the player
    void drinkPotion(const Potion& potion)
    {
        switch (potion.getType())
        {
        case Potion::health:
            // Only a health potion's size affects its power. All other
            // potions are independent of size.
            m_health += ((potion.getSize() == Potion::large) ? 5 : 2);
            break;
        case Potion::strength:
            ++m_damage;
            break;
        case Potion::poison:
            reduceHealth(1);
            break;
            // Handle max_type to silence the compiler warning. Don't use default:
            // because we want the compiler to warn us if we add a new potion but
            // forget to implement its effect.
        case Potion::max_type:
            break;
        }
    }

    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    inline static Creature monsterData[] {
        Creature { "dragon", 'D', 20, 4, 100 },
        Creature { "orc", 'o', 4, 2, 25 },
        Creature { "slime", 's', 1, 1, 10 }
        };

    static_assert(std::size(monsterData) == max_types);

public:
    Monster(Type type)
        : Creature{ monsterData[type] }
    {
    }

    static Monster getRandomMonster()
    {
        int num{ Random::get(0, max_types - 1) };
        return Monster{ static_cast<Type>(num) };
    }
};

// We moved this out of attackMonster() to keep the function shorter.
void onMonsterKilled(Player& player, const Monster& monster)
{
    std::cout << "You killed the " << monster.getName() << ".\n";
    player.levelUp();
    std::cout << "You are now level " << player.getLevel() << ".\n";
    std::cout << "You found " << monster.getGold() << " gold.\n";
    player.addGold(monster.getGold());

    // 30% chance of finding a potion
    constexpr int potionChance{ 30 };
    if (Random::get(1, 100) <= potionChance)
    {
        // Generate a random potion
        auto potion{ Potion::getRandomPotion() };

        std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
        char choice{};
        std::cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            // Apply the effect
            player.drinkPotion(potion);
            // Reveal the potion type and size
            std::cout << "You drank a " << potion.getName() << ".\n";
        }
    }
}

// This function handles the player attacking the monster
void attackMonster(Player& player, Monster& monster)
{
    // If the player is dead, we can't attack the monster
    if (player.isDead())
        return;

    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

    // Reduce the monster's health by the player's damage
    monster.reduceHealth(player.getDamage());

    // If the monster is now dead, level the player up
    if (monster.isDead())
    {
        // Reward the player
        onMonsterKilled(player, monster);
    }
}

// This function handles the monster attacking the player
void attackPlayer(const Monster& monster, Player& player)
{
    // If the monster is dead, it can't attack the player
    if (monster.isDead())
        return;

    // Reduce the player's health by the monster's damage
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

// This function handles the entire fight between a player and a randomly generated monster
void fightMonster(Player& player)
{
    // First randomly generate a monster
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

    // While the monster isn't dead and the player isn't dead, the fight continues
    while (!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char input{};
        std::cin >> input;
        if (input == 'R' || input == 'r')
        {
            // 50% chance of fleeing successfully
            if (Random::get(1, 2) == 1)
            {
                std::cout << "You successfully fled.\n";
                return; // success ends the encounter
            }
            else
            {
                // Failure to flee gives the monster a free attack on the player
                std::cout << "You failed to flee.\n";
                attackPlayer(monster, player);
                continue;
            }
        }

        if (input == 'F' || input == 'f')
        {
            // Player attacks first, monster attacks second
            attackMonster(player, monster);
            attackPlayer(monster, player);
        }
    }
}

int main()
{
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player player{ playerName };
    std::cout << "Welcome, " << player.getName() << '\n';

    // If the player isn't dead and hasn't won yet, the game continues
    while (!player.isDead() && !player.hasWon())
        fightMonster(player);

    // At this point, the player is either dead or has won
    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You won the game with " << player.getGold() << " gold!\n";
    }

  return 0;
}