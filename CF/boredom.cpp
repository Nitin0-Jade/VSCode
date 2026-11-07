
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n{};
    std::cin >> n;

    std::vector<long long> freq(100001, 0);

    int maxVal{0};

    for (int i = 0; i < n; ++i)
    {
        int x{};
        std::cin >> x;

        ++freq[x];
        maxVal = std::max(maxVal, x);
    }

    long long prev2{0};
    long long prev1{0};

    for (int x = 1; x <= maxVal; ++x)
    {
        long long take = prev2 + x * freq[x];

        long long skip = prev1;

        long long current = std::max(take, skip);

        prev2 = prev1;
        prev1 = current;
    }

    std::cout << prev1 << '\n';

    return 0;
}
