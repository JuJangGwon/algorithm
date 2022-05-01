#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char map[55][55];
bool bmap[55][55];
bool haha[2501];
int a, b, p_x,p_y;
void bfs(int x, int y)
{
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    bmap[y][x] = true;
    while(!q.empty())
    {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        for (int i = 0; i <= 4; i++)
        {
            int xx = x1 + dx[i];
            int yy = y1 + dy[i];
            if (xx >= 1 && x <= b && yy >= 1 && yy <= a)
            {
                if (!bmap[yy][xx])
                {
                if (map[yy][xx] == '*')
                {
                    q.push(make_pair(xx,yy));
                    bmap[yy][xx] = true;
                }
                else if (map[yy][xx] == '.')
                {
                    map[yy][xx] = '*';
                    bmap[yy][xx] = true;
                }
                }
            }
        }
    }
}
void clear()
{
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            bmap[i][j] = false;
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j<= b; j++)
        {
            if (!bmap[i][j] && map[i][j] == '*')
                bfs(j,i);
        }
    }
}
int bfs2()
{
    queue<pair<int, pair<int,int> > >q;
    q.push(make_pair(p_x,make_pair(p_y,0)));
    bmap[p_y][p_x] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second.first;
        int time = q.front().second.second;
        if (!haha[time])
        {
            haha[time] = true;
            clear();
        }
        q.pop(); 
        for (int i = 0; i< 4; i++)
        {
            int xx = x + dx[i];
            int yy = y +dy[i];
            if (yy >= 1 && xx >= 1 && xx <= b && yy <= a)
            {
                if (!bmap[yy][xx])
                {
                if (map[yy][xx] == '.')
                {
                    q.push(make_pair(xx,make_pair(yy,time+1)));
                    bmap[yy][xx] = true;
                }
                else if (map[yy][xx] == 'D')
                {
                    return time + 1;
                }
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j<= b; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                p_x = j;
                p_y = i;
            }
        }
    }
    int o = bfs2();
    if (o == -1)
    {
        cout << "KAKTUS";
    }
    else
        cout << o;
    return 0;
}