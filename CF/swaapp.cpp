#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{}, k{};
        std::cin >> n >> k;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            std::cin >> b[i];
        }

        std::sort(a.begin(), a.end());
        std::sort(b.rbegin(), b.rend());

        for (int i = 0; i < k; i++)
        {
            if (b[i] > a[i])
            {
                std::swap(a[i], b[i]);
            }
        }

        int sum{};

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }

        std::cout << sum << '\n';
    }

    return 0;
}