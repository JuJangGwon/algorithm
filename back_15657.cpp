#include <iostream>
#include <algorithm>

using namespace std;

int result[9];
int num[9];
int a, b;

void dfs(int c, int d)
{
    if (d == b)
    {
        for (int i = 0; i < b; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return ;
    }
    else
    {
        for (int i = c; i < a; i++)
        {
            result[d] = num[i];
            dfs(i, d+1);
        }
    }
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        cin >> num[i];
    }
    sort(num,num+a);
    dfs(0,0);
}