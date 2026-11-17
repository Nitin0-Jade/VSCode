#include <iostream>

int main()
{
    int t{},n{},a{},b{},c{};
    std::cin>> t;
    while(t--)
    {
            std::cin >> a >> b >> c;
            
            if(a==(b+c) || b==(a+c) || c==(a+b))
            {
                std::cout<< "yes\n";
            }
            else
            {
                std::cout<< "No\n";
            }
    }
}