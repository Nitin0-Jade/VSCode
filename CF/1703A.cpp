#include <iostream>
#include <string>

int main()
{
    std::string s{};
    int t{};
    std::cin>> t;
    while(t--)
    {
        std::cin>> s;
        if(s=="Yes" || s=="yes" || s=="yES" || s=="YEs" || s=="YeS" || s=="yEs" || s=="yeS" || s=="YES")
        {
            std::cout<< "YES\n";
        }
        else
        {
            std::cout<< "NO\n";
        }
    }
}