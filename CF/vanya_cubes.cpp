#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int used = 0;
    int layerCubes = 0;
    int height = 0;

    for (int i = 1; ; i++)
    {
        layerCubes += i;

        if (used + layerCubes > n)
            break;

        used += layerCubes;
        height++;
    }

    cout << height << '\n';

    return 0;
}