
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    sort(a.rbegin(), a.rend());

    int sum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        count++;

        if (sum > total - sum) {
            break;
        }
    }

    cout << count << endl;

    return 0;
}
