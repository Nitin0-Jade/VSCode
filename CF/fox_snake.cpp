
#include <iostream>

int main()
{
    int n{}, m{};
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i % 2 == 0)
            {
                std::cout << "#";
            }
            else if (i % 4 == 1)
            {
                if (j == m - 1)
                    std::cout << "#";
                else
                    std::cout << ".";
            }
            else
            {
                if (j == 0)
                    std::cout << "#";
                else
                    std::cout << ".";
            }
        }

        std::cout << '\n';
    }

    return 0;
}
