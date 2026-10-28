#include <iostream>
#include <algorithm>

int main()
{
    int n{}, a{}, b{}, m{};
    std::cin >> n >> m >> a >> b;

    int y = n / m;
    int r = n % m;

    int cost1 = n * a;
    int cost2 = y * b + r * a;
    int cost3 = (y + (r != 0)) * b;

    std::cout << std::min({cost1, cost2, cost3}) << '\n';
}