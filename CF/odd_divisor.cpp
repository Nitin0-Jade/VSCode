#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        if (n % 2 == 1) {
            std::cout << "YES\n";
        } else {
            while (n % 2 == 0) {
                n /= 2;
            }
            if (n > 1) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}