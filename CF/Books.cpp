#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0;
    int ans = 0;
    long long sum = 0;

    for (int right = 0; right < n; right++)
    {
        sum += a[right];

        while (sum > t)
        {
            sum -= a[left];
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans << '\n';
}