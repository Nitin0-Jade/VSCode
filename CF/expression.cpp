#include <iostream>
#include <algorithm>

int main()
{
    int a{},b{},c{},v{},q{},w{},x{};
    std::cin>> a;
    std::cin>> b;
    std::cin>> c;
    v=std::max(a+b*c,a*(b+c));
    q=std::max(a*b*c,(a+b)*c);
    w=std::max(a+b+c,a*b+c);
    x=std::max(q,w);
    std::cout<< std::max(v,x) << "\n";
}