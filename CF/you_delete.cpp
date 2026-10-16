#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        s.erase(s.find('0'), 1);
        s.erase(s.find('1'), 1);

        cout << s << '\n';
    }

    return 0;
}