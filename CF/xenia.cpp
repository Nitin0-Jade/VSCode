#include <iostream>

int main()
{
    int n{}, m{};
    std::cin >> n >> m;

    int current = 1;
    long long time = 0;

    for (int i = 0; i < m; i++)
    {
        int target{};
        std::cin >> target;

        if (target >= current)
        {
            time += target - current;
        }
        else
        {
            time += n - current + target;
        }

        current = target;
    }

    std::cout << time << '\n';

    return 0;
}