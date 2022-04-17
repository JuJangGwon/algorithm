#include <iostream>

using namespace std;

int n, m;
int num[9];

void dfs(int a, int b)
{
    if (b == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[i] << " ";
        }
        cout << "\n";
        return ;
    }
    else
    {
        for (int i = a; i <= n; i++)
        {
            num[b] = i;
            dfs(i, b + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1,0);

    return 0;
}