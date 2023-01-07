#include <iostream>

using namespace std;

int dp[10001];
int coin[101];

int main()
{
    int n, m;
    cin >> n >> m;
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= m; j++)
        {
            dp[j] += dp[j-coin[i]];
        }
    }
    cout << dp[m];
}