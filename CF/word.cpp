#include <iostream>
#include <string>
#include <cctype>

//bool hasUpper = std::any_of(s.begin(), s.end(), [](unsigned char c){ return std::isupper(c); });
//bool hasLower = std::any_of(s.begin(), s.end(), [](unsigned char c){ return std::islower(c); });


int main()
{
    std::string s;
    std::cin >> s;
    int upperCount = 0;
    int lowerCount = 0;

    for (char ch : s) {
        if (std::isupper(static_cast<unsigned char>(ch))) {
            upperCount++;
        } else if (std::islower(static_cast<unsigned char>(ch))) {
            lowerCount++;
        }
    }
    if(upperCount > lowerCount) {
        for (std::size_t i = 0; i < s.size(); ++i)
        {
            s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
        }
    }
    else 
    {
        for (std::size_t i = 0; i < s.size(); ++i)
        {
            s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
        }
    }
    std::cout << s << std::endl;
}