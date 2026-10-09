#include <iostream>
#include <string> // .h doesn't matter

//std::size_t len = word.size();
/*
========================================
 C vs C++ STRING CHEAT SHEET
========================================

TASK                  C-STYLE              C++ std::string
----------------------------------------------------------
Get length            strlen(word)         word.size()
First character       word[0]               word[0]
Last character        word[strlen(word)-1]  word.back()
Read a word           scanf(...)            std::cin >> word

EXAMPLE:
    std::string word{};
    std::cin >> word;

    word.size();  // Length of the string
    word[0];      // First character
    word.back();  // Last character (if non-empty!)

REMEMBER:
- Include <string> for std::string.
- Include <cstring> for strlen() on C-style strings.
- std::cin >> word reads one word, stopping at whitespace.
- word.back() requires a non-empty string.
- In C++, prefer std::string for ordinary string problems.

========================================
*/

int main(void)
{
    int n{};
    std::string word{};
    std::cin >> n;
    if (n>=1 && n<=100)
    {
        for(int i=0;i<n;i++)
        {
            std::cin>> word;
            std::size_t len = word.size();
            if (len>10)
            {
                std::cout << word[0]<<(len-2)<<word.back() << "\n";
            }
            else
            {
                std::cout << word << "\n";
            }
        }
    }
    else
    {
        return 1;
    }
    return 0;
}