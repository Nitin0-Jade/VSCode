#include <iostream>
#include <string>

int main()
{
    int x{0};
    int n{};
    std::cin >> n;

    std::string s{};

    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;

        if (s[1] == '+')
        {
            ++x;
        }
        else
        {
            --x;
        }
    }

    std::cout << x << '\n';

    return 0;
}