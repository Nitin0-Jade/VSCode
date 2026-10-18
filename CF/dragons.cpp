#include <iostream>
#include <vector>

int main()
{
    int s{},n{},c{};
    std::cin>> s >> n;
    if(s>=1 && s<=10000 && n>=1 && n<=1000)
    {
        for(int i{0};i<n;i++)
        {
            std::cin>> x >> y;
            if(x>=1 && x<=10000 && y>=0 && y<=10000)
            {
                if(s>x)
                {
                    s+=y;
                    c=0;
                }
                else
                {
                    c=1;
                }
            }
        }
        if(c==0)
        {
            std::cout<< "YES" << "\n";
        }
        else
        {
            std::cout<< "NO" << "\n";
        }
    }
}