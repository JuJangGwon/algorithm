#include <iostream>
#include <algorithm>

using namespace std;

int map[301];
int dp[301];

int main()
{
    int n;
    cin >> n;
    for (int i =1; i <= n; i++)
    {
        cin >> map[i];
    }
    dp[1] = dp[1];
    dp[2] = dp[1] + dp[2];
    dp[3] = max(dp[1]+dp[3], dp[2] + dp[3]);
    for (int i = 3; i <=n ;i++)
    {
        dp1[i] = max(dp[i])
    }

}