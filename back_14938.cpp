#include <iostream>
#include <queue>
#include <vector>
#define INF 2111111111
using namespace std;

int a, b, c;
vector<pair<int,int> >map[101];
int mapitem[101];
int dist[101];
int ans = 0;
void clear()
{
    for (int i = 1; i <= a; i++)
    {
        dist[i] = INF;
    }
}
void djikstra(int a)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int > > > pq;
    pq.push(make_pair(0,a));
    dist[a] = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[node] < cost)
            continue;
        for (int i = 0; i < map[node].size(); i++)
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
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
    {
        cin >> mapitem[i];
    }
    for (int i = 1; i <= c; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        map[a1].push_back(make_pair(a2,a3));
        map[a2].push_back(make_pair(a1,a3));
    }
    for (int i = 1; i <= a;i++)
    {
        clear();
        djikstra(i);
        int sum = 0;
        for (int j =1 ; j<=a ;j++)
        {
            if (dist[j] <= b)
            {
                sum += mapitem[j];
            }
        }
      //  cout << sum << "\n";
        ans = max(ans,sum);
    }
    cout << ans;
}