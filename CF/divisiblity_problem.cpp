#include <iostream>

int main()
{
    int t{};
    long long a{},b{},count{0};
    std::cin >> t;
    while (t--)
    {
        std::cin >> a >> b;
        if(a % b == 0)
        {
            std::cout << "0\n";
        }
        else
        {
            while(a % b != 0)
            {
                a++;
                count++;
            }
            std::cout << count << "\n";
            count = 0;
        }
    }
}

//




#include <iostream>

int main()
{
    int t{};
    long long a{}, b{};

    std::cin >> t;

    while (t--)
    {
        std::cin >> a >> b;

        long long rem = a % b;

        if (rem == 0)
            std::cout << 0 << '\n';
        else
            std::cout << b - rem << '\n';
    }

    return 0;
}
