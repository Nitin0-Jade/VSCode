#include <iostream>
#include <vector>
#include <utility>

int main()
{
    int n{}, m{};
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> children;

    for (int i{1}; i <= n; i++)
    {
        int candies{};
        std::cin >> candies;
        children.push_back({i, candies});
    }

    int last{};

    while (!children.empty())
    {
        auto child = children.front();
        children.erase(children.begin());

        child.second -= m;

        if (child.second > 0)
        {
            children.push_back(child);
        }
        else
        {
            last = child.first;
        }
    }

    std::cout << last << '\n';
}



if (child.second > 0)
{
    children.push_back(child);
}
else
{
    last = child.first;
}