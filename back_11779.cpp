#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 2111111111

using namespace std;

int a, b;
int st, ed;
vector<pair<int,int> > map[1001];
int dist[1001];
int track[1001];

void djikstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,st));
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
                track[nextnode] = node;
                dist[nextnode] = nextcost;
                pq.push(make_pair(dist[nextnode],nextnode));
            }
        }
    }
}

void clear()
{
    for (int i = 1; i <= a; i++)
    {
        dist[i] = INF;
    }
}

int main()
{
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        map[a1].push_back(make_pair(a2,a3));
    }
    cin >> st >> ed;
    clear();
    djikstra();
    cout << dist[ed] << "\n";
    int c = ed;
    int cot = 0;
    stack<int> track_s;
    while (1)
    {
        cot++;
        track_s.push(c);
        if (c == st)
            break;
        c = track[c];
    }
    cout << cot << "\n";
    while (!track_s.empty())
    {
        cout << track_s.top() << " ";
        track_s.pop();
    }
    return 0;
}