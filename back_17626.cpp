#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[50001] = {0,1};

int main()
{
    int a;

    cin >> a;

    for (int i = 2; i <= 50000; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j * j <= i; j++)
        {
            dp[i] = min(dp[i],dp[i-j*j] + 1);
        }
    }
    cout << dp[a];
    return 0;
}