#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,oo;
int map[21][21];

void cl(int ma[][21])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j <=n ;j++)
        {
            map[i][j] = ma[i][j];
        }
    }
}
void findmax()
{
    for (int i = 1 ; i <= n; i++)
    {
        for (int j =1 ; j <= n; j++)
        {
            oo = max(oo,map[i][j]);
        }
    }
}
bool same(int ma[][21])
{
    for (int i = 1; i<=n;i++)
    {
        for (int j =1; j<= n; j++)
        {
            if (map[i][j] != ma[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void dfs(int num)
{
    if (num == 10)
    {
        findmax();
        return ;
    }
    int tempmap[21][21];
    for (int i = 1; i<= n; i++)
    {
        for (int j =1 ;j<=n; j++)
        {
            tempmap[i][j] = map[i][j];
        }
    }
    // up
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        int whe = 1;
        for (int j = 1; j <= n; j++)
        {
            if(map[j][i])
            {
                if (temp != map[j][i])
                {
                    temp = map[j][i];
                    map[j][i] = 0;
                    map[whe++][i] = temp;
                }
                else
                {
                    map[whe-1][i] = map[whe-1][i] * 2;
                    map[j][i] = 0;
                    temp = 0;
                }
            }
        }
    }
    if (!same(tempmap))
    {
        dfs(num+1);
    }
    cl(tempmap);
    // down

    for (int i = n; i >= 1; i--)
    {
        int temp = 0;
        int whe = n;
        for (int j = n; j >= 1; j--)
        {
            if(map[j][i])
            {
                if (temp != map[j][i])
                {
                    temp = map[j][i];
                    map[j][i] = 0;
                    map[whe--][i] = temp;
                }
                else
                {
                    map[whe + 1][i] = map[whe + 1][i] * 2;
                    map[j][i] = 0;
                    temp = 0;
                }
            }
        }
    }
    if (!same(tempmap))
    {
        dfs(num+1);
    }
     cl(tempmap);
    // left
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        int whe = 1;
        for (int j = 1; j <= n; j++)
        {
            if(map[i][j])
            {
                if (temp != map[i][j])
                {
                    temp = map[i][j];
                    map[i][j] = 0;
                    map[i][whe++] = temp;
                }
                else
                {
                    map[i][whe-1] = map[i][whe-1] * 2;
                    map[i][j] = 0;
                    temp = 0;
                }
            }
        }
    }
     if (!same(tempmap))
    {
        dfs(num+1);
    }
    cl(tempmap);
    // right

    for (int i = n; i >= 1; i--)
    {
        int temp = 0;
        int whe = n;
        for (int j = n; j >= 1; j--)
        {
            if(map[i][j])
            {
                if (temp != map[i][j])
                {
                    temp = map[i][j];
                    map[i][j] = 0;
                    map[i][whe--] = temp;
                }
                else
                {
                    map[i][whe+1] = map[i][whe+1] * 2;
                    map[i][j] = 0;
                    temp = 0;
                }
            }
        }
    }
    if (!same(tempmap))
    {
        dfs(num+1);
    }
    cl(tempmap);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j =1 ;j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    dfs(0);
    cout << oo;
}