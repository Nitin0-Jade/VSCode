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

        int common{};

        if (a[0] == a[1] || a[0] == a[2])
        {
            common = a[0];
        }
        else
        {
            common = a[1];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] != common)
            {
                std::cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}