#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, r;
    cin >> k >> r;

    for (int i = 1; i <= 10; i++) {
        int price = (k * i) % 10;

        if (price == 0 || price == r) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
