
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    int sereja = 0, dima = 0;
    int turn = 0;

    while (l <= r) {
        int picked;

        if (a[l] > a[r]) {
            picked = a[l];
            l++;
        } else {
            picked = a[r];
            r--;
        }

        if (turn == 0) {
            sereja += picked;
        } else {
            dima += picked;
        }

        turn = 1 - turn;
    }

    cout << sereja << " " << dima << endl;

    return 0;
}
