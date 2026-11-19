
#include <iostream>
#include <vector>

int main()
{
    int n{}, h{}, a{}, count{0};
    std::cin >> n;

    std::vector<int> d(n);
    std::vector<int> e(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> d[i] >> e[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && d[i] == e[j])
            {
                count++;
            }
        }
    }

    std::cout << count << '\n';
}
