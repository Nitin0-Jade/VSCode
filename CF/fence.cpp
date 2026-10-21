#include <iostream>
#include <vector>

int main()
{
    int n{}, k{};
    std::cin >> n >> k;

    std::vector<int> h(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> h[i];
    }

    int sum{};

    // Calculate the first window's sum.
    for (int i = 0; i < k; i++)
    {
        sum += h[i];
    }

    int minSum = sum;
    int answer = 1;

    // Slide the window one position at a time.
    for (int i = k; i < n; i++)
    {
        sum += h[i];       // Add the new plank.
        sum -= h[i - k];   // Remove the plank that left.

        if (sum < minSum)
        {
            minSum = sum;
            answer = i - k + 2;
        }
    }

    std::cout << answer << '\n';

    return 0;
}