#include <iostream>
#include <algorithm>

using namespace std;

int t,m,n,b;
int visted[51][51];
int map[51][51];
int drx[4] = {0, 0, 1, -1};
int dry[4] = {1, -1,0, 0};

void reset()
{
    for (int yy = 0; yy < 51; yy++)
    {
        for (int xx = 0; xx < 51; xx++)
        {
            map[yy][xx] = 0;
            visted[yy][xx] = 0;
        }
    }

    
}

void dfs(int y,int x)
{
    visted[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int dy = dry[i] + y;
        int dx = drx[i] + x;
        if (dy >= 0 && dx >= 0 && dx < m && dy < n)
        {
            if (visted[dy][dx] == 0 && map[dy][dx] == 1)
                dfs(dy, dx);
        } 
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int i = 0; i< t; i++)
    {
        int sum = 0;
        cin >> m >> n >> b;
        for (int i = 0; i < b; i++)
        {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        for (int yy = 0; yy < n; yy++)
        {
            for (int xx = 0; xx < m; xx++)
            {
                if (map[yy][xx] == 1 && !visted[yy][xx])
                {
                    sum++;
                    dfs(yy,xx);
                }
            }
        }
        cout << sum << "\n";
        reset();
    }
    return 0;
}