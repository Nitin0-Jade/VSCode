#include <iostream>
#include <cmath>

int main()
{
    long long n{};
    long long sum{};

    std::cin >> n;

    for (long long i = 1; i <= n; ++i)
    {
        long long x = static_cast<long long>(std::pow(-1.0, i) * i);

        sum += x;
    }

    std::cout << sum << '\n';

    return 0;
}

//


#include <iostream>

int main()
{
    long long n{};

    std::cin >> n;

    if (n % 2 == 0)
    {
        std::cout << n / 2 << '\n';
    }
    else
    {
        std::cout << -((n + 1) / 2) << '\n';
    }

    return 0;
}