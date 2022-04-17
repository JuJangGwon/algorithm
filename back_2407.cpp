#include <iostream>
#include <algorithm>

int dp[1001];
int a[1001];

using namespace std;

int main()
{
    int b, c = 0;
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= b; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        c = max(dp[i],c);
    }
    cout << c;
    return 0;
}