#include <iostream>
#include <vector>

int main()
{
    int n{};
    std::cin >> n;
    std::vector a(n,0);
    std::vector<int> b;
    std::vector<int> c;

    for(int i{0};i<n;i++)
    {
        std::cin>> a[i];
        if(a[i]%2==0)
        {
            b.push_back(i);
        }
        else if(a[i]%2!=0)
        {
            c.push_back(i);
        }
    }
    if(b.size()==1)
    {
        std::cout<< b[0]+1 << "\n";
    }
    if(c.size()==1)
    {
        std::cout<< c[0]+1 << "\n";
    }
}