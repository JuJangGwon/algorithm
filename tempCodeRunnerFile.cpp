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
    for (int i = 1; i <= a.size(); i++)
    {   
        for (int j = 1; j <= b.size(); j++)
        {
           dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if (a[i-1] == b[j-1])
                dp[i][j]++;
        }
    }
    cout << dp[b.size()-1][a.size()-1];
    return 0;
}