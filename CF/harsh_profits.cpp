#include <iostream>

int main()
{
    int t{};
    std::cin >> t;

    if (t >= 1 && t <= 10000)
    {
        for (int i = 0; i < t; i++)
        {
            long long d{};
            std::cin >> d;

            long long profit = d * (d - 1) / 2;

            std::cout << profit << '\n';
        }
    }

    return 0;
}