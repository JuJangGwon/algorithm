#include <iostream>
#include <algorithm>

using namespace std;

int map[1001];
int dp[1001];

int main()
{
    int n,m;
    cin >> n;
    for (int i =1; i<=n; i++)
    {
        cin >> map[n];
    }
    for (int i =1; i <=n; i++)
    {
        for (int j = 1; j <=i;j++)
        {
            dp[i] = max(dp[i], dp[i-j] + map[j]);
        }
    }
}