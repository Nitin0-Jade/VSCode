#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> words(n);

        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }

        int answer = 1000;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int current = 0;

                for (int k = 0; k < m; k++)
                {
                    int d = words[i][k] - words[j][k];

                    if (d < 0)
                    {
                        d = -d;
                    }

                    current += d;
                }

                if (current < answer)
                {
                    answer = current;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}