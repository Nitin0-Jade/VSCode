#include <iostream>
#include <string>

int main()
{
    int n{}, count{0};
    std::cin >> n;

    std::string s{};

    for (int i = 0; i < n; i++)
    {
        std::cin >> s;

        if (s == "Tetrahedron")
            count += 4;
        else if (s == "Cube")
            count += 6;
        else if (s == "Octahedron")
            count += 8;
        else if (s == "Dodecahedron")
            count += 12;
        else if (s == "Icosahedron")
            count += 20;
    }

    std::cout << count << '\n';
}