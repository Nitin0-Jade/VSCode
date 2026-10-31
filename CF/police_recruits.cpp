#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int officers = 0;
    int untreated = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x > 0)
        {
            officers += x;
        }
        else
        {
            if (officers > 0)
                officers--;
            else
                untreated++;
        }
    }

    cout << untreated << '\n';

    return 0;
}