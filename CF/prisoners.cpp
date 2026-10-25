#include <iostream>
#include <vector>

int main()
{
    int n{}, t{}, c{};
    std::cin >> n >> t >> c;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int streak{};
    int ans{};

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= t)
        {
            streak++;

            if (streak >= c)
            {
                ans++;
            }
        }
        else
        {
            streak = 0;
        }
    }

    std::cout << ans << '\n';

    return 0;
}