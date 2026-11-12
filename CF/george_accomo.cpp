#include <iostream>

int main()
{
    int n{},p{},q{},count{0};
    std::cin>> n;
    for(int i{0};i<n;i++)
    {
        std::cin>> p >> q;
        if(p<q && (q-p)>=2)
        {
            count++;
        }
    }
    std::cout<< count << std::endl;
}