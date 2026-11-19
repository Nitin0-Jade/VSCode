#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s{},a{},b{},c{},e{}; //cuz empty string
    cin>> s;
    a.resize(s.size());
    e.resize(s.size());
    b.resize(s.size());
    c.resize(s.size());
    for(int i{0};i<s.size();i++)
    {
        a[i] = static_cast<unsigned char>(toupper(s[i]));
        e[i] = static_cast<unsigned char>(tolower(s[i]));
    }
    for(int i{1};i<s.size();i++)
    {
        c[i] = s[i];
        b[i] = static_cast<unsigned char>(toupper(s[i]));
    }
    if(s==a)
    {
        s=e;
    }
    else if((s[0]==tolower(a[0]) && c==b))
    {
        e[0]=static_cast<unsigned char>(toupper(e[0]));
        s=e;
    }
    cout<< s << "\n";
}


///



#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    std::cin >> s;

    bool change = true;

    for (int i = 1; i < s.size(); i++)
    {
        if (!std::isupper(static_cast<unsigned char>(s[i])))
        {
            change = false;
            break;
        }
    }

    if (change)
    {
        for (char &c : s)
        {
            unsigned char ch = static_cast<unsigned char>(c);

            if (std::islower(ch))
                c = std::toupper(ch);
            else
                c = std::tolower(ch);
        }
    }

    std::cout << s << '\n';

    return 0;
}
