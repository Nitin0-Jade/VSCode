#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{};
    std::cin >> n;

    std::vector<long long> v(n + 1);
    std::vector<long long> sorted(n + 1);

    for (int i = 1; i <= n; i++)
    {
        std::cin >> v[i];
        sorted[i] = v[i];
    }

    std::sort(sorted.begin() + 1, sorted.end());

    std::vector<long long> pref(n + 1, 0);
    std::vector<long long> prefSorted(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + v[i];
        prefSorted[i] = prefSorted[i - 1] + sorted[i];
    }

    int m{};
    std::cin >> m;

    while (m--)
    {
        int type{}, l{}, r{};
        std::cin >> type >> l >> r;

        if (type == 1)
        {
            std::cout << pref[r] - pref[l - 1] << '\n';
        }
        else
        {
            std::cout << prefSorted[r] - prefSorted[l - 1] << '\n';
        }
    }

    return 0;
}