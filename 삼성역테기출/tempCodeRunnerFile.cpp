#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n, m, mins = 2111111111;
int map[51][51];
int mmap[51][51];
bool bmap[51][51];
int space;
vector<pair<int,int> > v_p;
pair<int,int> now_v_p[11];
bool v_b[11];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int mapchecker()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j<= n ; j++)
        {
            //ma = max(ma, mmap[i][j]);
            if (mmap[i][j] == 0 && map[i][j] == 0)
                return 0;
        }
    }
    return 1;
}
void bfs()
{
    int sspace = 0;
    int a = 0;
    memset(mmap,0,sizeof(mmap));
    memset(bmap,0,sizeof(bmap));
    queue<pair<pair<int,int>,int> > q;
    for (int i = 0; i < m; i++)
    {
        q.push(make_pair(now_v_p[i],0));
        bmap[now_v_p[i].second][now_v_p[i].first] = 1;
    }
    while (!q.empty())
    {
        int x =q.front().first.first;
        int y =q.front().first.second;
        int time = q.front().second;
        q.pop();
        if (time >= mins)
            return ;
        a = max(a,time);
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && yy >= 1 && xx <= n && yy <= n)
            {
                if (!bmap[yy][xx] && map[yy][xx] != 1)
                {
                    if (map[yy][xx] == 0)
                    {
                        mmap[yy][xx] = time + 1;
                        q.push(make_pair(make_pair(xx,yy),time + 1));
                        sspace++;
                    }
                    else if (map[yy][xx] == 2)
                    {
                        mmap[yy][xx] = time+ 1;
                        q.push(make_pair(make_pair(xx,yy),time + 1));
                    }
                    bmap[yy][xx] = true;
                 
                }
            }
        }
    }
    if (sspace == space)
    {
        mins = min(a,mins);
    }
}

void dfs(int num, int now)
{
    if (num == m)
    {
        bfs();
        return ;
    }
    for (int i = now; i < v_p.size() - m + now + 1; i++)
    {
        if (!v_b[i])
        {
            v_b[i] = true;
            now_v_p[num] = make_pair(v_p[i].first,v_p[i].second);
            dfs(num + 1, now + 1);
            v_b[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                v_p.push_back(make_pair(j,i));
            }
            else if (map[i][j] == 0)
                space++;
        }
    }
    dfs(0,0);
    if (mins == 2111111111)
        cout << "-1";
    else
        cout << mins;
    return 0;
}