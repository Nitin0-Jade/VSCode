#include <iostream>

int main(void)
{
    long long n{};
    int k{};
    std::cin >> n >> k;
    if (n<=1000000000 && n>=2 && k>=1 && k<=50)
    {
        for(int i=0;i<k;i++)
        {
            if(n%10==0)
            {
                n/=10;
            }
            else
            {
                n--;
            }
        }
        std::cout << n << "\n";
    }
    else
    {
        return 1;
    }
    return 0;
}