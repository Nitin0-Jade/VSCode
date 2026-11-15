#include <iostream>

int main()
{
    int n{};
    std::cin >> n;

    int count = 0;

    int denominations[] = {100, 20, 10, 5, 1};

    for (int d : denominations)
    {
        count += n / d;
        n %= d;
    }

    std::cout << count << '\n';

    return 0;
}