#include <iostream>
#include <vector>

int main()
{
    int n{};
    std::cin >> n;

    std::vector<int> ans(n);

    for (int i = 1; i <= n; i++)
    {
        int x{};
        std::cin >> x;

        ans[x - 1] = i;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i];

        if (i < n - 1)
        {
            std::cout << " ";
        }
    }

    std::cout << '\n';

    return 0;
}