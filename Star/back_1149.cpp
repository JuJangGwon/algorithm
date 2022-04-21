#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][4];
int dp[1001][4];

int main()
{
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        cin >> map[i][1] >> map[i][2] >> map[i][3];
        dp[i][1] = min(dp[i-1][2],dp[i-1][3]) + map[i][1];
        dp[i][2] = min(dp[i-1][1],dp[i-1][3]) + map[i][2];
        dp[i][3] = min(dp[i-1][2],dp[i-1][1]) + map[i][3];
    }
    cout << min(dp[a][1],min(dp[a][2],dp[a][3]));
    return 0;
}