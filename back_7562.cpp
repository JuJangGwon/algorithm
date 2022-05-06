#include <iostream>
#include <queue>

using namespace std;

int n;
int map[301][301];
int a;
int x1,x2,y1,y2;
int dx[8] = {1, 2, 2, 1, -1, -2 , -1,-2};
int dy[8] = {2, 1, -1, -2, 2, 1, -2, -1};
bool bmap[301][301];
void reset()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            bmap[i][j] = 0;
            map[i][j] = 0;
        }
    }
}
void bfs()
{
    queue<pair<int, pair<int,int> > >q;
    q.push(make_pair(x1,make_pair(y1,0)));
    bmap[y1][x1] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second.first;
        int time = q.front().second.second;
        //cout << x << ", " << y << " | " << time << " ^ ";
        q.pop();
        if (x == x2 && y == y2)
            {
                cout << time << "\n";
                return ;
            }
        for (int i = 0; i < 8; i++)
        {
            int xx = x+dx[i];
            int yy = y +dy[i];
            
            if (xx >= 0 && xx< a && yy >= 0 && yy < a && !bmap[yy][xx])
            {
                bmap[yy][xx] = true;
                q.push(make_pair(xx,make_pair(yy,time +1)));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i =0 ; i < n ; i++)
    {
        cin >> a;
        cin >> x1 >> y1 >> x2 >> y2;
        bfs();
        reset();
    }
    return 0;
}