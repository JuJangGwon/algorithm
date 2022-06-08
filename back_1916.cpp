#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int> > v[1001];
int dist[1001];

void djikstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    dist[start] = 0;
    while(!pq.empty())
    {
        pair<int,int> par = pq.top();   
        int now = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();
        if (dist[par.second] < par.first)
            continue;
        for (int i = 0; i < v[par.second].size(); i++)
        {
            int nextcost = v[par.second][i].second + nowcost;
            int next = v[par.second][i].first;
            if (dist[next] > nextcost)
            {
                dist[next] = nextcost;
                pq.push(make_pair(dist[next],next));
            }
        }
    }

}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
      //  v[b].push_back(make_pair(c,a));
    }
    for (int i = 0; i <= n; i++)
    {
        dist[i] = 987654321;
    }
    int a, b;
    cin >> a >> b;
    djikstra(a);
    cout << dist[b];
    return 0;
}