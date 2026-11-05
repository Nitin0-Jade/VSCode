#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
    int n{}, m{};
    std::cin >> n;

    std::vector<int> boys(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> boys[i];
    }

    std::cin >> m;

    std::vector<int> girls(m);

    for (int i = 0; i < m; ++i)
    {
        std::cin >> girls[i];
    }

    std::sort(boys.begin(), boys.end());
    std::sort(girls.begin(), girls.end());

    int i{0}, j{0};
    int count{0};

    while (i < n && j < m)
    {
        if (std::abs(boys[i] - girls[j]) <= 1)
        {
            ++count;
            ++i;
            ++j;
        }
        else if (boys[i] < girls[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }

    std::cout << count << '\n';

    return 0;
}