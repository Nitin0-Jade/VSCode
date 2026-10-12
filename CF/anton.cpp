#include <iostream>
#include <string>
#include <cctype>

int main()
{
    long long n{};
    int count_a{},count_b{};
    std::string s{};
    std::cin>>n;
    if (n>=1 && n<=100000)
    {
        std::cin >> s;
        std::size_t len=s.size();
        if(len==n)
        {
            for (std::size_t i = 0; i < n; i++)
            {
                char x = std::toupper(static_cast<unsigned char>(s[i]));
                if (x=='A')
                {
                    ++count_a;
                }
                else
                {
                    ++count_b;
                }
            }
            if(count_a>count_b)
            {
                std::cout<< "Anton" << "\n";
            }
            else if(count_a<count_b)
            {
                std::cout<< "Danik" << "\n";
            }
            else
            {
                std::cout<< "Friendship" << "\n";
            }
        }
    }
}