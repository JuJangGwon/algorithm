#include <iostream>

using namespace std;

int map[31][31];
int arr[4];

int n, m, result = 0;

void dfs(int num, int k)
{
    if (num == 3)
    {
        int msum = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            for (int j = 0; j < num; j++)
            {
                temp = max(temp, map[i][arr[j]]);
            }
            msum += temp;
        }
        result = max(result, msum);
        return ;
    }
    for (int i = k; i <= m; i++)
    {
        arr[num] = i;
        dfs(num + 1, i + 1);
        arr[num] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    dfs(0, 1);
    cout << result;
}