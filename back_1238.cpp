#include <iostream>
#include <queue>
#include <vector>
#define INF 2111111111

using namespace std;

int a, b, c;
int maxx;
vector<pair<int,int> > map[1001];
int dist[1001];

void clear()
{
    for (int i = 1; i <= a; i++)
    {
        dist[i] = INF;
    }
}
int djikstra(int st, int ed)
{
    clear();
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,st));
    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[node] < cost)
            continue;
        for (int i = 0; i < map[node].size();i++)
        {
            int nextnode = map[node][i].first;
            int nextcost = map[node][i].second + cost;
            if (dist[nextnode] > nextcost)
            {
                dist[nextnode] = nextcost;
                pq.push(make_pair(nextcost,nextnode));
            }
        }
    }
    return dist[ed];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    for (int i = 1; i <= b; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        map[a1].push_back(make_pair(a2,a3));
    }
    for (int i = 1; i <= a; i++)
    {
        //if (i == c) continue;
        int a1 = djikstra(i,c);
        int a2 = djikstra(c,i);
        maxx = max(maxx,a1+a2);
    }
    cout << maxx;
    return 0;
}