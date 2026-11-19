#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int count{0},count_b{0};
    std::string a{},b{},c{};
    std::cin>> a;
    std::cin>> b;
    std::cin>> c;
    std::string d=a+b;
    std::sort(d.begin(),d.end());
    std::sort(c.begin(),c.end());
    if(d!=c)
    {
        std::cout<< "NO\n";
    }
    else
    {
        std::cout<< "YES\n";
    }
}