#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001] = {0, 1};
int sum = 0;

int main()
{
    int a;
    cin >> a;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= a; i++)
    {
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i/2] + 1, dp[i]);
        if (i % 3 == 0)
            dp[i] = min(dp[i/3] + 1, dp[i]);
    }
    cout << dp[a];
    return 0;
}