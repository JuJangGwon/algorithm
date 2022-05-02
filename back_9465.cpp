#include <iostream>
#include <algorithm>

int num1[100001];
int num2[100001];
int dp1[100001];
int dp2[100001];
int a, b;

using namespace std;
void clear()
{
    for (int i = 1; i <= b; i++)
    {
        num1[i] = 0;
        num2[i] = 0;
        dp1[i] = 0;
        dp2[i] = 0;
    }
}
int main()
{
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        for (int j = 1; j <= b; j++)
        {
            cin >> num1[j];
        }
        for (int j = 1; j <= b; j++)
        {
            cin >> num2[j];
        }
    dp1[1] = num1[1];
    dp2[1] = num2[1];
    dp1[2] = dp1[1] + num2[2];
    dp2[2] = dp2[1] + num1[1];
    for (int i = 1; i <= b; i++)
    {
        dp1[i] = max(dp2[i-1],dp2[i-2]) + num1[i];
        dp2[i] = max(dp1[i-1],dp1[i-2]) + num2[i];
    }
    cout << max(dp1[b],dp2[b]) << "\n";
    clear();
    }
    return 0;
}