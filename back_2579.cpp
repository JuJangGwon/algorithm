#include <iostream>
#include <algorithm>

using namespace std;

int dp[301] = {0,};

int main()
{
    int a;
    int v[301];
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        int t;
        cin >> t;
        v[i] = t;
    }
    dp[1] = v[1];
    dp[2] = v[2];
    dp[3] = v[3];

    for (int i = 4; i <= a; i++)
    {
        dp[i] = max(dp[i-3] + dp[i-1], dp[i-2]) + v[i]; 
    }
    return 0;

}