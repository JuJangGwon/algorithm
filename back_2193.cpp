#include <iostream>

using namespace std;

long long a;
long long dp[91];

int main()
{
    cin >> a;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= a; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[a];
    return 0;
}