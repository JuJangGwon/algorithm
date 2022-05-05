#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001][1001];

int main()
{
    string a, b;

    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[a.size()][b.size()] << "\n";
    int c = a.size();
    int d = b.size();
    vector<char> v;
    while (c != 0 && d != 0)
    {
        if(dp[c][d] == dp[c-1][d])
        {
            c--;
        }
        else if (dp[c][d] == dp[c][d-1])
        {
            d--;
        }
        else
        {
            v.push_back(a[c-1]);
            c--;
            d--;
        }
    }
    for (int i = v.size()-1; i > -1; i--)
    {
        cout << v[i];
    }
    return 0;
}