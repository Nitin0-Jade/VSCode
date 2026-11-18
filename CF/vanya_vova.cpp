#include <iostream>

int main()
{
    int t{},n{};
    std::cin >> t;
    while(t--)
    {
        std::cin>> n;
        if(n%3)
        {
            std::cout<< "First\n";
        }
        else
        {
            std::cout<< "Second\n";
        }
    }
}