#include <bits/stdc++.h>

int main()
{
    int n{};
    std::string s{};
    std::cin >> n;
    std::cin >> s;
    if (n < 26)
    {
        std::cout << "NO";
    }
    else
    {
        std::set<char> st;
        for (int i = 0; i < n; ++i)
        {
            st.insert(s[i]);
        }
        if (st.size() == 26)
        {
            std::cout << "YES";
        }
        else
        {
            std::cout << "NO";
        }
    }
}