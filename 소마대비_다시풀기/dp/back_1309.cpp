#include <iostream>

using namespace std;

int dp[100001];

int main()
{
    int num;

    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 7;

    cin >> num;

    for (int i =3; i <=num; i++)
    {
        dp[i] = ( (dp[i-1] * 2) + dp[i-2] ) % 9901;
    }

    cout << dp[num];
}