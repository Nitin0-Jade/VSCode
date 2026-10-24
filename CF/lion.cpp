#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s{};
    std::cin >> s;

    int n = static_cast<int>(s.size());

    std::vector<int> pref(n, 0);

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1];

        if (s[i] == s[i - 1])
        {
            pref[i]++;
        }
    }

    int m{};
    std::cin >> m;

    for (int i = 0; i < m; i++)
    {
        int l{}, r{};
        std::cin >> l >> r;

        std::cout << pref[r - 1] - pref[l - 1] << '\n';
    }

    return 0;
}