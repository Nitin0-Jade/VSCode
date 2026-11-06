
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{};
    std::cin >> n;

    std::vector<int> a(n);

    int ones{0};

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];

        if (a[i] == 1)
        {
            ++ones;
        }
    }

    int maxGain = -n;

    for (int i = 0; i < n; ++i)
    {
        int gain{0};

        for (int j = i; j < n; ++j)
        {
            if (a[j] == 0)
            {
                ++gain;
            }
            else
            {
                --gain;
            }

            maxGain = std::max(maxGain, gain);
        }
    }

    std::cout << ones + maxGain << '\n';

    return 0;
}
