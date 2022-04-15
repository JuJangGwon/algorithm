#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[1001][1001];
int a, b, ab, maxx = 0;

queue<pair<pair<int,int>,int> > q;


bool check()
{
    for (int i = 1; i <= b * ab; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            if (map[i][j] == 0)
            {
                return true; 
            }
        }
    }
    return false;
}

void bfs()
{

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        if (maxx < t)
            maxx = t;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
        if (xx > 0 && xx <= a && yy > 0 && yy <= b)
        {
            if (map[yy][xx] == 0)
            {
                q.push(make_pair(make_pair(xx,yy),t + 1));
                map[yy][xx] = 1;
            }
        }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> ab;

    for (int i = 1; i <= b * ab; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            int c; 
            cin >> c;
            if (c == 1)
            {
                q.push(make_pair(make_pair(j,i),0));
            }
            map[i][j] = c;
        }
    }
    if (check() == 0)
    {
        cout << "0";
        return 0;
    }
    bfs();
    if (check() == 1)
    {
        cout << "-1";
    }
    else
        cout << maxx;
    return 0;
}