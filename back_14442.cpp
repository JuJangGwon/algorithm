#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int map[1001][1001];
bool bmap[1001][1001][11];

int a, b, c;
int mins = -1;
void bfs()
{
    queue<pair<pair <int, int >,pair<int,int> > > q;
    q.push(make_pair(make_pair(1,1),make_pair(0,0)));
    bmap[1][1][0] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int breakblock = q.front().second.first;
        int time = q.front().second.second;
        q.pop();
        if (y == a && x == b)
            {
                mins = time+1;
                return ;
            }
        for (int i = 0; i <4;i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
         
            if (xx >= 1 && yy >= 1 && xx <= b && yy <= a) 
            {
                if (map[yy][xx]==0)
                {
                    if (!bmap[yy][xx][breakblock])
                    {
                        bmap[yy][xx][breakblock] = true;
                        q.push(make_pair(make_pair(xx,yy),make_pair(breakblock,time+1)));
                    }
                }
                else
                {
                    if (breakblock+1 <= c && !bmap[yy][xx][breakblock+1])
                    {
                        bmap[yy][xx][breakblock+1] = true;
                        q.push(make_pair(make_pair(xx,yy),make_pair(breakblock+1,time+1)));

                    }
                }
            }
        }
    }
}
int main()
{
    cin >> a >> b >> c;
    for (int i = 1; i<= a; i++)
    {
        for (int j = 1;j <= b; j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    bfs();
    cout << mins;
    return 0;
}