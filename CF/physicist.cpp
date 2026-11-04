#include <iostream>

int main()
{
    int n{},x{},y{},z{},count_a{},count_b{},count_c{};
    std::cin>> n;
    for(int i{0};i<n;i++)
    {
        std::cin>> x >> y >> z;
        count_a+=x;
        count_b+=y;
        count_c+=z;
    }
    if(count_a==0 && count_b==0 && count_c==0)
    {
        std::cout<< "YES\n";
    }
    else
    {
        std::cout<< "NO\n";
    }
}