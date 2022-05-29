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
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j =1; j<= a; j++)
        {
            dp[i][j] = map[i][j] + dp[i][j-1] + dp[i-1][j]- dp[i-1][j-1];
        }
    }
    for (int i = 0; i<b; i++)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        cout << dp[b1][b2] +dp[a1-1][a2-1] - dp[a1-1][b2] - dp[b1][a2-1] << "\n";
    }
    //     for (int i = 1; i <=a; i++)
    // {
    //     for (int j = 1; j <= a; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}