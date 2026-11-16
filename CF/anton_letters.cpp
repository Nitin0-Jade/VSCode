
#include <iostream>
#include <string>
#include <set>

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::set<char> ans;

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            ans.insert(c);
        }
    }

    std::cout << ans.size() << '\n';

    return 0;
}
