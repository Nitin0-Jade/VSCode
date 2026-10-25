#include <iostream>

int main()
{
    int t{};
    std::cin >> t;

    while (t--)
    {
        long long n{}, k{};
        std::cin >> n >> k;

        long long ans = k + (k - 1) / (n - 1);

        std::cout << ans << '\n';
    }

    return 0;
}