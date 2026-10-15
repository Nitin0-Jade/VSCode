#include <iostream>
#include <string>
#include <cctype>

int main()
{
    int t{};
    std::string s;
    std::cin>>t;
    std::size_t len = s.size();
    if(t>=1 && t<=100)
    {
        int m{},n{};
        std::cin>> n >> m;
        if(n>=2 && n<=50 && m>=1 && m<=8)
        {
            if(len==m)
            {
                for(int i{0};i<n;++i)
                {
                    std::cin>> s;
                    char x=std::tolower(static_cast<unsigned char>(s))
                    

                    

                }

            }
            
        }
    }
}