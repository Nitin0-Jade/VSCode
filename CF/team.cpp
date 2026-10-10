#include <iostream>

int main(void)
{
    int n{},d{},e{},f{},count{0};
    std::cin>> n;
    for(int i=0;i<n;i++)
    {
        std::cin>> d >> e >> f;
        if ((d==0 || d==1) && (e==0 || e==1) && (f==0 || f==1))
        {
            if (d+e+f >=2 )
            {
                ++count;
            }
        }
        else
        {
            return 1;
        }
    }
    std::cout<< count << "\n";
    return 0;
}