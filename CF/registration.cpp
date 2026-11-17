
#include <iostream>
#include <map>
#include <string>

int main()
{
    int n{};
    std::cin >> n;

    std::map<std::string, int> users;

    while (n--)
    {
        std::string name;
        std::cin >> name;

        if (users[name] == 0)
        {
            std::cout << "OK\n";
        }
        else
        {
            std::cout << name << users[name] << '\n';
        }

        users[name]++;
    }

    return 0;
}
