#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int mapb[101][101];
int dx[4] = {1,-1, 0,0};
int dy[4] = {0,0, 1,-1};
int sum = 0;

void bfs(int x, int y)
{
    queue<pair<int,int> > bf;
    bf.push(make_pair(1,1));
    mapb[1][1] = 1;

    while (!bf.empty())
    {

        int xo = bf.front().first;
        int yo = bf.front().second;
      //  cout << xo << yo << " " << mapb[yo][xo] << "/";
        bf.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = xo + dx[i];
            int yy = yo + dy[i];

            if (xx >= 1 &&xx <= y && yy >= 1 && yy <= x && map[yy][xx] && !mapb[yy][xx])
            {
                bf.push(make_pair(xx,yy));
                mapb[yy][xx] = mapb[yo][xo] + 1;
            }
        }
    }
}
int main()
{
    int a, b;
    cin.tie(NULL);

    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            scanf("%1d",&map[j][i]);
        }
    }
    bfs(b,a);
    cout << mapb[b][a];
    return 0;
}