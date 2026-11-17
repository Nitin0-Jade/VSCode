#include <iostream>
#include <map>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    std::map<std::string, int> users;

    while (n--)
    {
        std::string name;
        std::cin >> name;

        if (users[name] == 0)
        {
            std::cout << "OK\n";
            users[name] = 1;
        }
        else
        {
            int &suffix = users[name];

            while (users[name + std::to_string(suffix)] != 0)
                suffix++;

            std::string newName = name + std::to_string(suffix);
            users[newName] = 1;
            suffix++;

            std::cout << newName << '\n';
        }
    }

    return 0;
}