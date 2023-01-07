#include <iostream>
#include <algorithm>

using namespace std;

int r[1001];
int b[1001];
int g[1001];

int dp1[1001];
int dp2[1001];
int dp3[1001];

int main()
{
    int n;
    cin >> n;
    for (int i =1; i<= n;i++)
    {
        cin >> r[i] >> b[i] >> g[i];
    }
    dp1[1] = r[1];
    dp2[1] = g[1];
    dp3[1] = b[1];

    for (int i = 2; i <=n; i++)
    {
        dp1[i] = min(dp2[i-1] , dp3[i-1]) + r[i];
        dp2[i] = min(dp1[i-1] , dp3[i-1]) + g[i];
        dp3[i] = min(dp1[i-1] , dp2[i-1]) + b[i];
    }
    int result = min(dp1[n],dp2[n]);
    cout << min(result,dp3[n]);

}