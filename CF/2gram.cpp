#include <iostream>
#include <string>

int main()
{
    int n{};
    std::cin >> n;

    std::string s{};
    std::cin >> s;

    int maxCount{};
    std::string answer{};

    for (int i = 0; i < n - 1; i++)
    {
        std::string gram = s.substr(i, 2);
        int count{};

        for (int j = 0; j < n - 1; j++)
        {
            if (s.substr(j, 2) == gram)
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            answer = gram;
        }
    }

    std::cout << answer << '\n';

    return 0;
}