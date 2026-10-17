#include <iostream>
#include <string>

int main()
{
    int n{}, t{};
    std::cin >> n >> t;

    std::string s{};
    std::cin >> s;

    for (int sec = 0; sec < t; sec++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'B' && s[i + 1] == 'G')
            {
                s[i] = 'G';
                s[i + 1] = 'B';

                i++;
            }
        }
    }

    std::cout << s << '\n';
}