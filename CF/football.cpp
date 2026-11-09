
#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int count{1};

    for (std::size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            ++count;
        }
        else
        {
            count = 1;
        }

        if (count >= 7)
        {
            std::cout << "YES\n";
            return 0;
        }
    }

    std::cout << "NO\n";

    return 0;
}
