#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long d;
    cin >> n >> d;

    vector<pair<long long, long long>> friends(n);

    for (int i = 0; i < n; i++)
    {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    long long sum = 0;
    long long ans = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        sum += friends[right].second;

        while (friends[right].first - friends[left].first >= d)
        {
            sum -= friends[left].second;
            left++;
        }

        ans = max(ans, sum);
    }

    cout << ans << '\n';

    return 0;
}