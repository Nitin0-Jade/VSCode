#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s{},t{};
    std::cin>> s;
    std::cin>> t;
    std::reverse(t.begin(),t.end());
    if(s==t)
    {
        std::cout<<"YES\n";
    }
    else
    {
        std::cout<<"NO\n";
    }
}