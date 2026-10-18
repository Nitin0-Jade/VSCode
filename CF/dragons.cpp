#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    int s{}, n{};
    std::cin >> s >> n;

    std::vector<std::pair<int, int>> dragons(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> dragons[i].first >> dragons[i].second;
    }

    std::sort(dragons.begin(), dragons.end());

    for (int i = 0; i < n; i++)
    {
        int x = dragons[i].first;
        int y = dragons[i].second;

        if (s <= x)
        {
            std::cout << "NO\n";
            return 0;
        }

        s += y;
    }

    std::cout << "YES\n";

    return 0;
}