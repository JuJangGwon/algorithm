#include <iostream>
#include <queue>
#include <vector>
#define inf 2111111111
int a, b;

using namespace std;
vector<pair<int,int> > v[20001];
int dist[20001];

void djikstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty())
    {
        int now = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();
        if (dist[now] < nowcost)
            continue;
        for (int i = 0; i < v[now].size(); i++)
        {
           // cout << v[now].size() << "\n";
            int next = v[now][i].first;
            int nextcost = v[now][i].second + nowcost;
            //cout << now << " : " << nowcost << " : " << next << " : " << nextcost << "\n";
            if (dist[next] > nextcost)
            {
                dist[next] = nextcost;
                pq.push(make_pair(nextcost,next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //

    cin >> a >> b;
    int start;
    cin >> start;
    for (int i = 1; i <= b; i++)
    {
        int a1,a2,a3;
        cin >> a1 >> a2 >> a3;
        v[a1].push_back(make_pair(a2,a3));
    }
    for (int i = 1; i<= a; i++)
    {
        dist[i] = inf;
    }
    djikstra(start);
    for (int i = 1; i <= a; i++)
    {
        if(dist[i] != 2111111111)
            cout <<dist[i] << "\n";
        else
            cout <<"INF\n";
    }
    return 0;
}