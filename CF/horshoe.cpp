
#include <iostream>
#include <set>

int main()
{
    long long s1{}, s2{}, s3{}, s4{};
    std::cin >> s1 >> s2 >> s3 >> s4;

    std::set<long long> colors{s1, s2, s3, s4};

    std::cout << 4 - colors.size() << '\n';

    return 0;
}
