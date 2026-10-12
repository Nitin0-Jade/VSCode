#include <iostream>
#include <vector>

int main()
{
    int n{};
    std::cin >> n;

    if (n >= 1 && n <= 1000)
    {
        std::vector<int> w(n);

        for (int i = 0; i < n; i++)
        {
            std::cin >> w[i];
        }

        int count{};
        int highest = w[0];
        int lowest = w[0];

        for (int i = 1; i < n; i++)
        {
            if (w[i] > highest)
            {
                ++count;
                highest = w[i];
            }
            else if (w[i] < lowest)
            {
                ++count;
                lowest = w[i];
            }
        }

        std::cout << count << '\n';
    }
    else
    {
        return 1;
    }

    return 0;
}