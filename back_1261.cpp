#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool bmap[101][101];
    int a, b;

int djikstra()
{
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int > > > > pq;
    pq.push(make_pair(0,make_pair(1,1)));
    bmap[1][1] = true;
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int breakblock = pq.top().first;
       // cout << x << ", " << y << " | " << breakblock << endl;
        if (x == a && y == b)
        {
            return breakblock;
        }
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1&& yy >= 1 && xx <=a && yy <= b)
            {
                if (!bmap[yy][xx])
                {
                    if (map[yy][xx] == 0)
                    {
                        pq.push(make_pair(breakblock, make_pair(xx,yy)));
                    }
                    else
                        pq.push(make_pair(breakblock+1, make_pair(xx,yy)));
                    bmap[yy][xx] = true;
                }
            }
        }
    }
    return 0;
}
int main()
{
    cin >> a >> b;
    for (int i =1; i <= b; i++)
    {
        for (int j = 1; j<=a;j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    cout << djikstra();
    return 0;
}