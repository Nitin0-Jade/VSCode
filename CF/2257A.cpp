#include <iostream>
#include <vector>
#include <string>
#include <cctype>


int main()
{
    int m{},n{},t{};
    std::string s{},q{};
    std::cin>>t;
    if(t>=1 && t<=500)
    {
        for(int i=0;i<t;i++)
        {
            std::cin>> n >> m;
            for(int j=0;j<n;j++)
            {
                std::cin>> s;
                std::vector<char> a(n);
                a[i]= std::toupper(static_cast<unsigned char>(s[0]));
            }
            for(int w=0;w<n;w++)
            {
               std::vector<string> b(n);
               c
               b[i]=b.push_back(a[i]+a[i+1]);
               
            }
            for(int k=0;k<m;k++)
            {
                std::cin>> q;
            }
            if()


        }
    }
}