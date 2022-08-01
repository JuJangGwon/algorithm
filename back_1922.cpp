#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, sum;
vector<pair<int,int> >v[1001];      // 입력 받을 그래프 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;       
int visited[1001];

void prim(int node)
{
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!visited[v[node][i].second])
        {
            pq.push(make_pair(v[node][i].first,v[node][i].second));
        }
    }
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int nextnode = pq.top().second;
        pq.pop();
        if (!visited[nextnode])
        {
            sum += cost;
            prim(nextnode);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        v[a1].push_back(make_pair(a3,a2));
        v[a2].push_back(make_pair(a3,a1));
    }
    prim(1);
    cout << sum;
    return 0;
}