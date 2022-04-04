#include <iostream>

using namespace std;

long long dp[91] = {0, 1,};

long long fibo(long long c)
{
    if (c == 0)
        return dp[0];
    else if (c== 1)
        return 1;
    else if (dp[c] == 0)
        dp[c] = fibo(c-1) + fibo(c-2);
    return dp[c];
}
int main()
{
    long long a;
    cin >> a;
    cout << fibo(a);
    return 0;
}