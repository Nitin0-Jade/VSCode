
#include <iostream>
#include <vector>

int main()
{
    int n{};
    std::cin >> n;

    int police = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int x{};
        std::cin >> x;

        if (x > 0)
        {
            police += x;
        }
        else
        {
            if (police > 0)
                police--;
            else
                count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}
