#include <iostream>
#include <algorithm>

int main()
{
    int n{},l{},nl{},k{},c{},d{},p{},np{};
    std::cin>> n >> k >> l >> c >> d >> p >> nl >> np;
    std::cout<< (std::min(std::min((k*l)/nl,c*d),p/np))/n << std::endl;
}