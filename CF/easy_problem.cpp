#include <iostream>
#include <vector>

int main() {
    int n{},count{0};
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 1) {
            count++;
        }
    }
    if(count!=0)
        std::cout << "Hard" << std::endl;
    else
    {
        std::cout << "Easy" << std::endl;
    }
}