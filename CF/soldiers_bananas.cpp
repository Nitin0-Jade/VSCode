#include <iostream>

int main()
{
    int w{},k{},pay{},total_pay{};
    long long n{};
    std::cin >> k >> n >> w;
    if(1<=k && w<=1000 && 0<=n && n<=1000000000)
    {
        for(int i=1;i<=w;i++)
        {
            pay= i*k;
            total_pay+=pay;
        }
        if(total_pay <= n)
        {
            std::cout << 0 << "\n";
        }
        else
        {
            std::cout << total_pay-n << "\n";
        }
    }
    else
    {
        return 1;
    }
    return 0;
}