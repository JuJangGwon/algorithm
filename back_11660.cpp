#include <iostream>

using namespace std;

int map[1025][1025];
long long dp[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, piror = 0;
    cin >> a >> b;
    for (int i = 1; i <=a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            cin >> map[i][j];
            piror += map[i][j];
            dp[i][j] = piror;
            
        }
    }

    for (int i = 0; i < b; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if (x1 == x2 && y1 == y2)
        {
            cout << map[y2][x2] << "\n";
        }
        else
            if (!(y1 == 1 && x1 == 1))
            {
                cout << dp[y2][x2] - dp[y1][x1] << "\n";
            }
            else
                cout << dp[y2][x2] << "\n";
    }
    return 0;
}