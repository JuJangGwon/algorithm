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
        if (dist[par.second] < par.first)     // 이미 거리비용이 , 큐에 담겨잇는 비용보다 작으면 skip
            continue;
        for (int i = 0; i < v[par.second].size(); i++)
        {
            int nextcost = v[par.second][i].second + nowcost;       // 다음 비용 = 지금 비용 + 다음 노드의 비용
            int next = v[par.second][i].first;                       // 다음 노드
            if (dist[next] > nextcost)                      // 만약에 다음 노드의 비용이 계산된 비용보다 클때 최신화
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