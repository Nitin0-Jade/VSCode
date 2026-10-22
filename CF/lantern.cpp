#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    int n{};
    long long l{};

    std::cin >> n >> l;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    double r = std::max(
        static_cast<double>(a[0]),
        static_cast<double>(l - a[n - 1])
    );

    for (int i = 0; i < n - 1; i++)
    {
        double gap = (a[i + 1] - a[i]) / 2.0;

        if (gap > r)
        {
            r = gap;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << r << '\n';

    return 0;
}