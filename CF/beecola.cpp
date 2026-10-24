#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{}, q{}, m{};
    std::cin >> n;

    std::vector x(n, 0);

    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }

    std::sort(x.begin(), x.end());

    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        std::cin >> m;

        auto it = std::upper_bound(x.begin(), x.end(), m);

        int count = it - x.begin();

        std::cout << count << '\n';
    }

    return 0;
}