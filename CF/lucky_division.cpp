
#include <iostream>
#include <vector>

int main()
{
    int n{};
    std::cin >> n;

    std::vector<int> lucky{
        4, 7,
        44, 47, 74, 77,
        444, 447, 474, 477,
        744, 747, 774, 777
    };

    bool isAlmostLucky{false};

    for (int x : lucky)
    {
        if (n % x == 0)
        {
            isAlmostLucky = true;
            break;
        }
    }

    std::cout << (isAlmostLucky ? "YES" : "NO") << '\n';

    return 0;
}
