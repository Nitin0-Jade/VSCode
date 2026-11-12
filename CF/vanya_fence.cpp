#include <iostream>
#include <vector>

int main()
{
    int n{},h{},count{0};
    std::cin >> n >> h;
    std::vector<int> a(n);
    for(int i{0};i<n;i++)
    {
        std::cin >> a[i];

        if(a[i]>h)
        {
            count+=2;
        }
        else
        {
            count+=1;
        }
    }
    std::cout << count << std::endl;
}