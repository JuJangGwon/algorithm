#include <iostream>

using namespace std;

int dp[11];

int main()
{
    int testcase;
    cin >> testcase;

    dp[1] = 1;              // 1
    dp[2] = 2;              // 1 1,   2
    dp[3] = 4;              // 1 1 1,    1 2      ,  2  1    ,    3 

    for (int i =4 ;i <= 10; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for (int i =0; i < testcase; i++)
    {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
    return 0;

}