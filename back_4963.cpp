#include <iostream>

using namespace std;

int a, b;
int map[51][51];
bool bmap[51][51];

int dx[8] = { 0, 0, 1 ,-1,1, -1, 1,-1};
int dy[8] = { 1,-1, 0, 0, 1, -1,-1, 1};
void clear(int x, int y)
{
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            bmap[i][j] = 0;
            map[i][j] = 0;
        }
    }
}

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && yy >= 1 && xx <= a && yy <= b)
        {
            if (!bmap[yy][xx] && map[yy][xx])
            {
                bmap[yy][xx] = true;
                dfs(xx,yy);
            }
        }
    }
}

int main()
{
    while (1)
    {
        int sum = 0;
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;
        for (int i = 1; i <= b; i++)
        {
            for (int j = 1; j <= a; j++)
            {
                cin >> map[i][j];
            }
        }
        for (int i = 1; i <= b; i++)
        {
            for (int j = 1; j <= a; j++)
            {
                if (!bmap[i][j] && map[i][j] == 1)
                {
                    dfs(j,i);
                    sum++;
                }
            }
        }
        cout << sum << "\n";
        clear(a,b);
    }
}