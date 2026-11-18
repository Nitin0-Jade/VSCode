/*
Key differences:

std::replace	std::string::replace
Replaces	single elements (e.g. one char)	substrings by position
Header	<algorithm>	member of std::string
Signature	replace(first, last, old, new)	replace(pos, len, str)

*/

#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    size_t pos = 0;
    while ((pos = s.find("WUB", pos)) != std::string::npos)
    {
        s.replace(pos, 3, " ");
        pos += 1; // advance past the replaced space
    }

    std::cout << s << std::endl;
}   