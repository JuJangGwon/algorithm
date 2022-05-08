#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[301][301];
int tempmap[301][301];

bool bmap[301][301];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int _x,int _y)
{
    queue<pair <int , pair<int, int> > > p;
    p.push(make_pair(_x,make_pair(_y,0)));
    bmap[_y][_x] = 1;
    while (!p.empty())
    {
        int x = p.front().first;
        int y = p.front().second.first;
        int time = p.front().second.second;
        int sum = 0;
        p.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
            {
                if (!map[yy][xx] && !tempmap[y][x])
                    tempmap[y][x]--;
                if (map[yy][xx] && !bmap[yy][xx])
                {
                    p.push(make_pair(xx,make_pair(yy,time +1)));
                    bmap[yy][xx] = true;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    int num = 1;
    while (num == 1)
    {
        num = 0;
        for (int i = 1; i<= n; i++)
        {
            for (int j = 1; j <=m;j++)
            {
                tempmap[i][j] = map[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j =1 ;j <= m; j++)
            {
                if (map[i][j] && !bmap[i][j])
                {
                    num++;
                    bfs(j,i);
                }
            }
        }
        for (int  i = 1; i <=n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                bmap[i][j] = 0;
            }
        }
    }
    cout << num;
}