#include <iostream>

using namespace std;

long long dp[1001] = {0,1,3};
int main()
{
    int a;
    cin >> a;
    for (int i = 3; i<= a; i++)
    {
        dp[i] = (dp[i-1] +dp[i-2] * 2)% 10007;
    }
    cout << dp[a];
    return 0;
}