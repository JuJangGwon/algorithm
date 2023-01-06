#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[26][26];
bool visited[26][26];
vector<int> result;
int n;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int _x, int _y)
{
    int c = 0;
    queue<pair <int,pair <int ,int> > > q;
    q.push(make_pair(1,make_pair(_x,_y)));
    visited[_y][_x] = true;
    while(!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int top = q.front().first;
        c++;
        q.pop();
        for (int i =0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n &&yy >= 1 && yy <= n)
            {
                if (!visited[yy][xx] && map[yy][xx] == 1)
                {
                    q.push(make_pair(top + 1, make_pair(xx,yy)));
                    visited[yy][xx]= true;
                }
            }
        }
    }
    return c;
}

int main()
{
    cin >> n;
    for (int i =1; i <=n ;i ++)
    {
        for (int j = 1; j <=n ; j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    for (int i =1; i <=n ;i++)
    {
        for (int j = 1; j <=n ; j++)
        {
         
            if(map[i][j] == 1 && !visited[i][j])
            {
                result.push_back(bfs(j,i));
            }
        }
    }    

    sort(result.begin(),result.end());
    cout << result.size() << "\n";
    for (int i =0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}