
#include <iostream>
#include <vector>

int main()
{
    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> ans;
        int place = 1;

        while (n > 0)
        {
            int digit = n % 10;

            if (digit != 0)
            {
                ans.push_back(digit * place);
            }

            n /= 10;
            place *= 10;
        }

        std::cout << ans.size() << '\n';

        for (int x : ans)
        {
            std::cout << x << ' ';
        }

        std::cout << '\n';
    }

    return 0;
}
