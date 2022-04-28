#include <iostream>
#include <queue>
#include <vector>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

using namespace std;

char map[30][30][30];
bool bmap[30][30][30];

int x,y,z;

void reset()
{
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k <x; k++)
            {
                map[i][j][k] = '\0';
                bmap[i][j][k] = 0;
            }
        }
    }
}

int bfs()
{
    queue<pair<pair <int,int>,pair<int,int> > >q;
    q.push(make_pair(make_pair(0,0),make_pair(0,0)));
    bmap[0][0][0] = true;
    while (!q.empty())
    {
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int zz = q.front().second.first;
        int time = q.front().second.second;
        q.pop();
        if (map[zz][yy][xx] == 'E')
        {
            return time;
        }
        for (int i = 0; i < 4; i++)
        {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            if (!bmap[zz][yyy][xxx] && yyy >= 0 && yyy < y && xxx >= 0 && xxx < x && map[zz][yyy][xxx] != '#')
            {
                bmap[zz][yyy][xxx] = true;
                q.push(make_pair(make_pair(xxx,yyy),make_pair(zz,time+1)));
            }
        }
        if (!bmap[zz+1][yy][xx] && map[zz+1][yy][xx] != '#')
        {
            bmap[zz+1][yy][xx] = true;
            q.push(make_pair(make_pair(xx,yy),make_pair(zz+1,time+1)));
        }
    }

    return -1;
}

int main()
{
    while (1)
    {
        cin >> z >> y >> x;
        if (z == 0 && y == 0 && x == 0)
            return 0;
        for (int i = 0; i < z; i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < x; k++)
                {
                    cin >> map[i][j][k];
                }
            }
        }
        int o = bfs();
        if (o == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << o << " minute(s).\n";
        reset();
    }
    return 0;

}