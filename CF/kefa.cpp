#include <iostream>
#include <vector>

int main()
{
    int n{},current{1},best{1};
    std::cin>> n;
    std::vector<int> a(n);
    for(int i{0};i<n;i++)
    {
        std::cin >> a[i];
    }
    for(int i{1};i<n;i++)
    {
       if(a[i]>=a[i-1])
       {
        current++;
       }
       else
       {
        current=1;
       }
       if(current > best)
       {
        best = current;
       }
    }
    std::cout<< best << "\n";
}