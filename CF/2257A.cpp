#include <iostream>
#include <vector>
#include <string>

int main()
{
    int t{};
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n{}, m{};
        std::cin >> n >> m;

        std::vector<int> a(26, 0);

        std::string s{};

        for (int j = 0; j < n; j++)
        {
            std::cin >> s;

            a[s[0] - 'a'] = 1;
        }

        bool possible = true;

        for (int j = 0; j < m; j++)
        {
            std::string q{};
            std::cin >> q;

            for (int k = 0; k < q.size(); k++)
            {
                if (a[q[k] - 'A'] == 0)
                {
                    possible = false;
                }
            }
        }

        if (possible)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}