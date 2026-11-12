#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());
        long long maxHeight = a[n - 1];

        std::vector<long long> left, middle, right;
        int k = 0;

        int i = 0;
        while (i < n)
        {
            // find how many books have the same height as a[i]
            int j = i;
            while (j < n && a[j] == a[i])
            {
                j++;
            }
            int count = j - i;
            long long h = a[i];

            // one copy always goes on the left side
            left.push_back(h);
            k++;

            if (h == maxHeight)
            {
                // extra copies of the tallest book go in the middle
                for (int x = 1; x < count; x++)
                {
                    middle.push_back(h);
                }
                if (count >= 2)
                {
                    k++; // last copy is visible from the right
                }
            }
            else
            {
                if (count >= 2)
                {
                    right.push_back(h); // second copy goes on the right side
                    k++;
                    for (int x = 2; x < count; x++)
                    {
                        middle.push_back(h); // remaining copies are hidden
                    }
                }
            }

            i = j;
        }

        std::cout << k << "\n";

        for (int x = 0; x < (int)left.size(); x++)
        {
            std::cout << left[x] << " ";
        }
        for (int x = 0; x < (int)middle.size(); x++)
        {
            std::cout << middle[x] << " ";
        }
        for (int x = (int)right.size() - 1; x >= 0; x--)
        {
            std::cout << right[x] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}