#include <iostream>

using namespace std;

long long dp[1000001];

int main()
{
    int a;
    cin >> a;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= a; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[a];
    return 0;
}