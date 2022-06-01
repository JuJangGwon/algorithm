#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> v[32001];
int node_N[32001];
int rs[32001];

int n,m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        node_N[b]++;
    }
    for (int i = 1; i <=n ; i++)
    {
        if (node_N[i] == 0)
        {
            q.push(i);
        }
    }
    int o = 1;
    while(!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int j = 0; j < v[x].size(); j++)
        {
            int d = v[x][j];
            node_N[d]--;
            if (node_N[d] == 0)
                q.push(d);
        }
    }
    return 0;
}