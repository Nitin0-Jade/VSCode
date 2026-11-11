#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string s{};
    std::cin >> s;
    std::vector<int> a{};
    for (char c : s)
    {
        if (c != '+')
        {
            a.push_back(c - '0');
        }
    }
    std::sort(a.begin(), a.end());
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        if (i > 0)
        {
            std::cout << '+';
        }

        std::cout << a[i];
    }
    std::cout << '\n';
}