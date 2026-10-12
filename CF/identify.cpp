#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s{};
    std::cin >> s;

    std::vector<int> seen(26, 0);
    int count{};

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';

        if (seen[index] == 0)
        {
            seen[index] = 1;
            ++count;
        }
    }

    if (count % 2 == 0)
    {
        std::cout << "CHAT WITH HER!\n";
    }
    else
    {
        std::cout << "IGNORE HIM!\n";
    }

    return 0;
}