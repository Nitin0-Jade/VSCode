#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n{}, m{}, count{};
    std::cin >> n >> m;

    std::vector<std::string> grid(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> grid[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            std::string square;
            square += grid[i][j];
            square += grid[i][j + 1];
            square += grid[i + 1][j];
            square += grid[i + 1][j + 1];

            if (std::find(square.begin(), square.end(), 'f') != square.end() &&
                std::find(square.begin(), square.end(), 'a') != square.end() &&
                std::find(square.begin(), square.end(), 'c') != square.end() &&
                std::find(square.begin(), square.end(), 'e') != square.end())
            {
                count++;
            }
        }
    }

    std::cout << count << '\n';
    return 0;
}