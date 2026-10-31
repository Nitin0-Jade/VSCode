#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 1;

    // Number of children removed in the first round
    int first_round = (n + 1) / 2;

    // The kth child is removed in the first round
    if (k <= first_round)
    {
        int ans = 2 * k;

        if (ans > n)
            ans -= n;

        return ans;
    }

    // Find the answer in the smaller circle
    int x = josephus(n / 2, k - first_round);

    // Map the smaller circle's answer to the original circle
    if (n % 2 == 0)
        return 2 * x - 1;
    else
        return 2 * x + 1;
}

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n, k;
        cin >> n >> k;

        cout << josephus(n, k) << '\n';
    }

    return 0;
}