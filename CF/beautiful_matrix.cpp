#include <iostream>
#include <cstdlib>

int main()
{
    int x{};
    int row{};
    int col{};

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            std::cin >> x;

            if (x == 1)
            {
                row = i;
                col = j;
            }
        }
    }

    int count = std::abs(row - 3) + std::abs(col - 3);

    std::cout << count << '\n';

    return 0;
}