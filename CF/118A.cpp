#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s{};
    std::cin >> s;

    for (std::size_t i = 0; i < s.size(); ++i)
    {
        char x = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));

        if (x == 'a' || x == 'e' || x == 'i' ||
            x == 'o' || x == 'u' || x == 'y')
        {
            continue;
        }

        std::cout << '.' << x;
    }

    std::cout << '\n';
}