#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{}, m{};
    std::cin >> n >> m;

    std::vector<int> f(m);

    for (int i = 0; i < m; i++)
    {
        std::cin >> f[i];
    }

    std::sort(f.begin(), f.end());

    int smallest = f[n - 1] - f[0];

    for (int i = 1; i <= m - n; i++)
    {
        int difference = f[i + n - 1] - f[i];

        if (difference < smallest)
        {
            smallest = difference;
        }
    }

    std::cout << smallest << '\n';

    return 0;
}