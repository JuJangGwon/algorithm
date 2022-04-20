#include <iostream>
#include <string>

using namespace std;

string a, b;
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= b.size(); i++)
    {   
        for (int j = 1; j <= a.size(); j++)
        {
            if (b[i-1] == a[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            
        }
    }
    cout << dp[b.size()][a.size()];
    return 0;
}