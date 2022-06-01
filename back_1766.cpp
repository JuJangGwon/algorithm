#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[32001];
int tmap[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int> > q;
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        tmap[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (tmap[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.top();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < v[x].size();i++)
        {
            int y = v[x][i];
            tmap[y]--;
            if (tmap[y] == 0)
                q.push(y);
        }
    }
}