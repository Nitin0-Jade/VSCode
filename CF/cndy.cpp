#include <iostream>
#include <vector>

int main()
{
    int t{};
    std::cin >> t;

    while (t--)
    {
        int n{};
        std::cin >> n;

        std::vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        int smallest = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] < smallest)
            {
                smallest = a[i];
            }
        }

        long long answer = 0;

        for (int i = 0; i < n; i++)
        {
            answer += a[i] - smallest;
        }

        std::cout << answer << '\n';
    }

    return 0;
}