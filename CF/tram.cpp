#include <iostream>

int main()
{
    int n{},a{},b{},p{},count{},temp{};
    std::cin>>n;
    if(n>=2 && n<=1000)
    {
        for(int i=1;i<=n;i++)
        {
            std::cin>> a >> b;
            p = b-a;
            count+=p;
            if(count>temp)
            {
                temp=count;
            }
        }
        std::cout<< temp << "\n";
    }
}