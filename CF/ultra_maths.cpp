#include <iostream>
#include <string>

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << ((a[i] - '0') ^ (b[i] - '0'));
    }

    std::cout << '\n';

    return 0;
}

//

#include <iostream>
#include <string>

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
            std::cout << '0';
        else
            std::cout << '1';
    }

    std::cout << '\n';

    return 0;
}