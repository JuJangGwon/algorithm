#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[8];
int ans[8];
int check[8];

void DFS(int level, int node)
{
    if (level == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = node; i < n; i++)
    {
        if (check[i] == 0)
        {
            check[i] = 1;
            ans[level] = a[i];
            DFS(level + 1, i + 1);
            check[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    DFS(0, 0);
}