#include <iostream>
#include <string>
#include <string_view> // C++17

// Our monster struct represents a single monster

struct Monster
{
	// Define our different monster types as an enum
	enum Type
	{
		ogre,
		dragon,
		orc,
		giant_spider,
		slime,
	};

	Type type{};
	std::string name{}; // the Monster should be an owner of its name
	int health{};
};

// Return the name of the monster's type as a string
// Since this could be used elsewhere, it's better to make this its own function
constexpr std::string_view getMonsterTypeString(Monster::Type type)
{
	switch (type)
	{
	case Monster::ogre:          return "Ogre";
	case Monster::dragon:        return "Dragon";
	case Monster::orc:           return "Orc";
	case Monster::giant_spider:  return "Giant Spider";
	case Monster::slime:         return "Slime";
	}

	return "Unknown";
}

// Print our monster's stats
void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) <<
		" is named " << monster.name <<
		" and has " << monster.health << " health.\n";
}

int main()
{
	Monster ogre{ Monster::ogre, "Torg", 145 };
	Monster slime{ Monster::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}