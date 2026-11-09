
#include <iostream>

int main()
{
    int n{};
    std::cin >> n;

    int count{0};

    while (n > 0)
    {
        int x = n % 10;

        if (x == 4 || x == 7)
        {
            ++count;
        }

        n /= 10;
    }

    if (count == 4 || count == 7)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}
