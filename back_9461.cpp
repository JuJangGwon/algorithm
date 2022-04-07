#include <iostream>

using namespace std;

long long dp[101];

int main()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    int a;
    cin >> a;
    for (int i = 5; i < 101; i++)
    {
        dp[i] = dp[i-3] + dp[i-2];
    }
    for (int i = 0; i< a; i++)
    {
        int b;
        cin >> b;
        cout << dp[b] << "\n";
    }
    return 0;
}