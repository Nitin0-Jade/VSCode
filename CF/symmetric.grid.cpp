#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int t{};
    std::cin >> t;

    for (int test = 0; test < t; test++)
    {
        int n{};
        std::cin >> n;

        std::vector<std::string> a(n);

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        int ans{};

        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int ones{};

                if (a[i][j] == '1') ones++;
                if (a[j][n - 1 - i] == '1') ones++;
                if (a[n - 1 - i][n - 1 - j] == '1') ones++;
                if (a[n - 1 - j][i] == '1') ones++;

                ans += std::min(ones, 4 - ones);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}