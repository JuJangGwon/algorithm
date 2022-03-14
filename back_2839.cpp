#include <iostream>

using namespace std;

int dp(int a, int _5, int _3)
{
    if ((a < 3 && a > 0) || a == 4 || a < 0)
    {
        cout << "-1";
        return 0;
    }
    else if (a == 0)
    {
        cout << _5 + _3;
        return 0;
    }
    return dp(a - 5, ++_5, _3) + dp(a - 3, _5, ++_3);
}

int main(void)
{
    int d;
    cin >> d;
    dp(d, 0, 0);
    return 0;
}