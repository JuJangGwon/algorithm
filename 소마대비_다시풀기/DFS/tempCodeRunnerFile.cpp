#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> map[1001];
bool visited[1001];

void dfs(int a)
{
    cout << a << " ";
    visited[a] = true;
    for (int i =0; i < map[a].size(); i++)
    {
        if (!visited[map[a][i]])
        {
    
            dfs(map[a][i]);
        }
    }
}

void bfs(int a)
{
    queue<int> q;
    q.push(a);
    visited[a] = true;
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
        cout << num << " ";
        for (int i =0; i < map[a].size(); i++)
        {
            if (!visited[map[a][i]])
            {
                visited[map[a][i]] = true;
                q.push(map[a][i]);
            }
        }
    }
}
int main()
{
    int n,m,c;
    cin >> n >> m>> c;
    for (int i =1; i <= m;i++)
    {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    dfs(c);
    memset(visited,false,sizeof(visited));
    cout << "\n";
    bfs(c);
}