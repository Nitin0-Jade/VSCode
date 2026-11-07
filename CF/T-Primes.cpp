
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    const int LIMIT = 1000000;

    // Sieve of Eratosthenes
    std::vector<bool> isPrime(LIMIT + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= LIMIT; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= LIMIT; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int n{};
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        long long x{};
        std::cin >> x;

        long long root = sqrtl(x);

        if (root * root == x && isPrime[root])
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
