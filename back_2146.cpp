#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

queue<pair<int,pair<int,int > > > pq;
int map[101][101];
bool visited[101][101];
vector<pair<int,int> > v;


int n, result = 999999;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs2(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    visited[y][x] = true;
    while (!q.empty())
    {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= n && !visited[next_y][next_x])
            {
                if (map[next_y][next_x] == 1)
                {
                    visited[next_y][next_x] = true;
                    q.push(make_pair(next_x, next_y));
                }
                else if (map[next_y][next_x] == 0)
                {
                    pq.push(make_pair(0, make_pair(next_x, next_y)));
                    visited[next_y][next_x] = true;
                }
            }
        }
    }
}

void bfs()
{
    while (!pq.empty())
    {
        int dist = pq.front().first;
        int now_x = pq.front().second.first;
        int now_y = pq.front().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= n && !visited[next_y][next_x])
            {
                if (map[next_y][next_x] == 0)
                {
                    visited[next_y][next_x] = true;
                    pq.push(make_pair(dist + 1, make_pair(next_x, next_y)));
                }
                else if (map[next_y][next_x] == 1)
                {
                    result = min(result,dist + 1);      // 초기화
                    return ;
                }
            }
        }
    }
}

void findAREA()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == false)
            {
                v.push_back(make_pair(j,i));
                visited[i][j] = true;
                bfs2(j, i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool abc = false;
    cin >> n;
    for (int i = 1; i <= n; i++) // 입력
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    findAREA();
    
    int a = v.size();
  
    for (int i = 0; i < a; i++)
    {
       memset(visited,false,sizeof(visited));
       pq = queue<pair<int,pair<int,int > > >();
       bfs2(v[i].first,v[i].second);
       bfs();

    }
     if (result == 999999)
     result = 0;
    cout << result;
}