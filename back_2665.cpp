#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int map[51][51];
bool visited[51][51];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs()
{
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int > > > ,greater<pair<int,pair<int,int> > > > pq;
    pq.push(make_pair(0,make_pair(1,1)));
    visited[1][1] = true;
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int breakblock = pq.top().first;
        if (x == n && y == n)
        {
            cout << breakblock;
            return ;
        }
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i]; 
            if (xx >= 1 && yy >= 1 && xx <= n && yy <= n && !visited[yy][xx])
            {
                if (map[yy][xx] == 0)
                    pq.push(make_pair(breakblock+1,make_pair(xx,yy)));
                else
                    pq.push(make_pair(breakblock,make_pair(xx,yy)));
                visited[yy][xx] = true;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    bfs();
    return 0;
}