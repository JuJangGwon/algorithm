#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int> >v[1001];
int dis[1001];

void dijkstra(int s)
{
    priority_queue<pair<int ,int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,s));
    dis[s] = 0;
    while(!pq.empty())
    {
        pair<int,int> par = pq.top();
        pq.pop();
        if (dis[s] < par.first)
            continue;
        for (int i = 0; i < v[s].size(); i++)
        {
            int next = v[s][i].first;
            if (dis[next] > dis[par.second] + v[par.second][i].first)
            {
                dis[next] = dis[par.second] + v[par.second][i].first;
                pq.push(make_pair(dis[next],next));
            }
        }
    }
}
int main()
{
    int n, m, o,oo;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for (int i = 1 ; i <= n; i++)
    {
        dis[i] = 999999999;
    }
    cin >> o >> oo;
    dijkstra(o);
    cout << dis[oo];

}