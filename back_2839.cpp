#include <iostream>

using namespace std;

int i = 0;

void dfs(int a, int _5, int _3)
{
    if ((a < 3 && a > 0) || a == 4 || a < 0)
    {
        return ;
    }
    else if (a == 0)
    {
        cout << _5 + _3;
        i++;
        return ;
    }
    if (i == 0) dfs(a - 5, _5+1, _3);
    if (i == 0) dfs(a - 3, _5, _3+ 1);
}

int main(void)
{
    int d;
    cin >> d;
    dfs(d, 0, 0);
    if (i == 0)
        cout << "-1";
    return 0;
}