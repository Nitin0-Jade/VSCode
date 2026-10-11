#include <iostream>
#include <string>

int main(void)
{
    int n{},count{0};
    std::string s{};
    std::cin >> n;
    std::cin >> s;
    if (n>=1 && n<=50)
    {
        for(int i=0;i<n;i++)
        {
            if ((s[i]=='R' && s[i+1]=='R') || (s[i]=='G' && s[i+1]=='G') || (s[i]=='B' && s[i+1]=='B'))
            {
                ++count;
            }
            else
            {
                count;
            }
        }
        std::cout<< count << "\n";
    }
    else
    {
        return 1;
    }
    return 0;
}