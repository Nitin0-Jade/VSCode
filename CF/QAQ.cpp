#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int n = static_cast<int>(s.size());
    int ans = 0;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (s[i] == 'Q' &&
                    s[j] == 'A' &&
                    s[k] == 'Q')
                {
                    ans++;
                }
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}