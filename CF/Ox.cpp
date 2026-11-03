#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
/*WRONG BECUZ AVG NOT MEDIAN
int main()
{
    int sum{0},avg{};
    std::vector a(3,0);
    for(int i{0};i<3;i++)
    {
        std::cin>> a[i];
    }
    std::sort(a.begin(),a.end());
    for(int i{0};i<3;i++)
    {
        sum+=a[i];
    }
    avg=sum/3;
    std::cout<< std::abs(a[0]-avg) + std::abs(a[1]-avg) + std::abs(a[2]-avg) << "\n";
}*/

int main()
{
    std::vector<int> a(3);

    for (int i = 0; i < 3; i++)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());

    int median = a[1];

    int ans = std::abs(a[0] - median)
            + std::abs(a[1] - median)
            + std::abs(a[2] - median);

    std::cout << ans << '\n';
}

//Better soln
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
    std::vector<int> a(3);

    for (int i = 0; i < 3; i++)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());
    std::cout << a[2]-a[0] << '\n';
}
