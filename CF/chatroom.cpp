
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "hello";
    int j = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target[j]) {
            j++;
        }

        if (j == 5) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
