#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{};
    std::cin >> n;

    std::vector<int> count(5, 0);

    for (int i = 0; i < n; i++)
    {
        int x{};
        std::cin >> x;
        count[x]++;
    }

    int taxis = count[4] + count[3];

    count[1] = std::max(0, count[1] - count[3]);

    taxis += count[2] / 2;

    if (count[2] % 2 == 1)
    {
        taxis++;
        count[1] = std::max(0, count[1] - 2);
    }

    taxis += (count[1] + 3) / 4;

    std::cout << taxis << '\n';

    return 0;
}