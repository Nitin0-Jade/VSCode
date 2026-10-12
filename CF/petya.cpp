#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string a{}, b{};

    std::cin >> a >> b;

    std::size_t len = a.size();

    for (std::size_t i = 0; i < len; i++)
    {
        char x = std::toupper(static_cast<unsigned char>(a[i]));
        char y = std::toupper(static_cast<unsigned char>(b[i]));

        if (x < y)
        {
            std::cout << -1 << '\n';
            return 0;
        }
        else if (x > y)
        {
            std::cout << 1 << '\n';
            return 0;
        }
    }

    std::cout << 0 << '\n';

    return 0;
}