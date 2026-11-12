#include <iostream>
#include <cmath>

int main()
{
    int t{},a{},b{},c{};
    std::cin >> t;
    for(int i{0}; i < t; ++i)
    {
        std::cin >> a >> b >> c;
        if((abs(a-b)==1 && abs(b-c)==1) || (abs(a-b)==1 && abs(b-c)==2 && abs(a-c)==1) || (abs(a-b)==2 && abs(b-c)==1 && abs(a-c)==1))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}