#include <bits/stdc++.h>

int main()
{
    std::string s{};
    std::cin >> s;
    int count = 0;
    for (char c : s) {
        if (c == 'H' || c == 'Q' || c == '9') {
            count++;
        }
    }
    if (count > 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}