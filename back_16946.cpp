#include <iostream>
#include <queue>

using namespace std;

int x, y, sum;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int> >q;
int map[1001][1001];
bool bmap[1001][1001];
int ans[1001][1001];

void dfs(int x1,int y1)
{
    queue<pair <int , int > >qq;
    q.push(make_pair(x1,y1));
    while (!q.empty())
    {
        int x2 = qq.front().first;
        int y2 = qq.front().second;
        qq.pop();
        for (int i = 0; i < 4; i++)
    {
        int xx = x2+dx[i];
        int yy = y2+dy[i];
        if (xx >= 1 && xx <= x && yy >= 1 && yy <= y)
        {
            if (map[yy][xx] == 0)
            {
                bmap[yy][xx] = true;
                sum++;
                q.push(make_pair(xx,yy));
                qq.push(make_pair(xx,yy));
            }
        }
    }
    }
}

int main()
{
    cin >> y >> x;
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (map[i][j] == 1)
            {
                sum = 1;
                dfs(j,i);
                ans[i][j] = sum % 10;
                while(!q.empty())
                {
                    int xx = q.front().first;
                    int yy = q.front().second;
                    q.pop();
                    bmap[yy][xx] = 0; 
                }
            }
        }
    }
    for (int i = 1; i <= y; i++)
    {
        for (int j =1 ; j<= x ; j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}