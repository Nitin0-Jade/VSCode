#include <iostream>
#include <vector>

int main()
{
    int n{}, p{}, q{}, count{};

    std::cin >> n;

    std::vector<int> a(n, 0);
    std::vector<int> b(n, 0);

    std::cin >> p;

    for (int i = 0; i < p; i++)
    {
        int level{};
        std::cin >> level;

        a[level - 1] = 1;
    }

    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        int level{};
        std::cin >> level;

        b[level - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 || b[i] == 1)
        {
            ++count;
        }
    }

    if (count == n)
    {
        std::cout << "I become the guy.\n";
    }
    else
    {
        std::cout << "Oh, my keyboard!\n";
    }

    return 0;
}