#include <iostream>

using namespace std;

int map[8];
int n, m;

void dfs(int num)
{
    if (m == num)
    {
        for (int i =0; i < m; i++)
        {
            cout << map[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for (int i = 1; i <=n; i++)
    {
        map[num] = i;
        dfs(num+1);
        map[num] = 0;
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
}