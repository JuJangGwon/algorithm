#include <iostream>
#include <algorithm>

using namespace std;

int map[301];
int dp[301]; 

int main()
{
    int n;
    cin >> n;
    for (int i =1; i <= n; i++)     // 입력
    {
        cin >> map[i];
    }

    dp[1] = map[1];                 
    dp[2] = map[1] + map[2];                                
    dp[3] = max(map[1]+map[3], map[2] + map[3]);            // 1 - 3 , 2 - 3 고룬 경우중 최댓값

    for (int i = 4; i <=n ;i++)
    {
        dp[i] = max(map[i]+dp[i-2],map[i] + map[i-1] + dp[i-3]);
    }
    cout << dp[n];
}