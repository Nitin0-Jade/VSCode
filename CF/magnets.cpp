#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    std::string prev;
    std::cin >> prev;

    int count = 1;

    for (int i = 1; i < n; i++)
    {
        std::string s;
        std::cin >> s;

        if (s != prev)
            count++;

        prev = s;
    }

    std::cout << count << '\n';

    return 0;
}