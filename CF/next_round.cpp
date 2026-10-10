#include <iostream>

int main()
{
    int n{}, k{};

    if (!(std::cin >> n >> k) ||
        n < 1 || n > 50 ||
        k < 1 || k > n)
    {
        return 1;
    }

    int threshold{};
    int cleared{};

    for (int i = 0; i < n; ++i)
    {
        int score{};

        if (!(std::cin >> score) || score < 0 || score > 10000)
        {
            return 1;
        }

        if (i == k - 1)
        {
            threshold = score;
        }

        if (i < k)
        {
            if (score > 0)
            {
                ++cleared;
            }
        }
        else if (score > 0 && score >= threshold)
        {
            ++cleared;
        }
    }

    std::cout << cleared << '\n';
    return 0;
}