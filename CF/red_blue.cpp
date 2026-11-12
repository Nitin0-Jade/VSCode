#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::string s;
        std::cin >> n >> s;

        char pen = 'R';   // pen starts in red
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != pen)
            {
                count++;      // manual switch
                pen = s[i];
            }

            // the pen flips by itself after writing
            if (pen == 'R')
            {
                pen = 'B';
            }
            else
            {
                pen = 'R';
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}