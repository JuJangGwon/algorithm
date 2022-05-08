#include <iostream>
#include <queue>

using namespace std;

int n;
int map[21][21];
bool bmap[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs()
{
    queue<pair <int , pair<int, int> > > p;
    p.push(make_pair(3,make_pair(3,0)));
    bmap[3][3] = true;
    while (!p.empty())
    {
        int x = p.front().first;
        int y = p.front().second.first;
        int time = p.front().second.second;
        cout << "[ " << x << ", " << y << " ] time : " << time << " | " ;
        p.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !bmap[yy][xx])
            {
           p.push(make_pair(xx,make_pair(yy,time +1)));
                
                bmap[yy][xx] = true;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = 0;
        }
    }
    map[3][3]= true;
    bfs();
}