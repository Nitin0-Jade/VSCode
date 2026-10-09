#include <iostream>

int main(void)
{
    int w{};
    std::cin>> w ;
    if (w>=1 && w<=100)
    {
        if (w%2==0 && w>2)
        {
            std::cout<< "YES" << "\n";
        }
        else
        {
            std::cout<< "NO" << "\n";
        }
    }
    else
    {
        return 1;
    }
    return 0;
}