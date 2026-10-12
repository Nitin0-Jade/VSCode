#include <iostream>
#include <vector>

int main()
{
    int n{},sum{0};
    double output{};
    std::cin>>n;
    if(n>=1 && n<=1000)
    {
        std::vector<int> p(n);
        for(int i=0;i<n;i++)
        {
            std::cin>> p[i];
            sum+=p[i];
        }
        output = static_cast<double>(sum)/n;
        std::cout<< output << "\n";
    }
}