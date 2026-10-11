#include <iostream>

int main()
{
    long long x{};
    long long steps{};

    std::cin >> x;

    steps = x / 5;

    if (x % 5 != 0)
    {
        ++steps;
    }

    std::cout << steps << '\n';

    return 0;
}