#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{}, k{};
    std::cin >> n >> k;

    std::vector a(n, 0);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    if (k == 0)
    {
        if (a[0] > 1)
        {
            std::cout << a[0] - 1 << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }
    else if (k == n || a[k - 1] < a[k])
    {
        std::cout << a[k - 1] << '\n';
    }
    else
    {
        std::cout << -1 << '\n';
    }

    return 0;
}