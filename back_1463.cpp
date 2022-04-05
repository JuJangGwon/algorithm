#include <iostream>

using namespace std;

int dp[1000001] = {0, 1};
int sum = 0;

int main()
{
    int a;
    cin >> a;
    
    for (int i = 2; i <= a; i++)
    {
        dp[i] = dp[i-1] + 1;
        
    }
    cout << --sum;
    return 0;
}