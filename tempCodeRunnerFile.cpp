#include <iostream>

using namespace std;

int a[100001];
int dp[100001];
int an;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int b;
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        dp[i] = a[i];
        cin >> a[i];
        if (a[i] + dp[i-1] > dp[i])
            dp[i] = a[i] + dp[i-1];
        if (dp[i] > an)
            an = dp[i];
    }
    cout << an;
    return 0;
}