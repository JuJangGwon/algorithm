#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b;
vector<pair<int,int> > v[801];
int dist[801];

void clear()
{
    for (int i =0; i <=a ;i++)
    {
        dist[i] = 1e9+7;
    }
}

int djikstra(int st,int end)
{
    clear();
    priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int > > > pq;
    pq.push(make_pair(0,st));
    dist[st] = 0;
    while(!pq.empty())
    {
        int value = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (dist[node] < value)
            continue;
        for (int i = 0; i < v[node].size(); i++)
        {
            int newvalue = v[node][i].second+ value;
            int newnode = v[node][i].first;
            if (dist[newnode] > newvalue)
            {
                dist[newnode] = newvalue;
                pq.push(make_pair(newvalue,newnode));
            }
        }
    }
    return dist[end];
}

int main()
{
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        v[a1].push_back(make_pair(a2,a3));
        v[a2].push_back(make_pair(a1,a3));
    }
    int o1,o2,ans1,ans2;
    cin >> o1 >> o2;
    int a1 = djikstra(1,o1);
    int a2 = djikstra(o1,o2);
    int a3 = djikstra(o2,a);
    if (a1 == 1e9+7 || a2 == 1e9+7 || a3 == 1e9+7)
        ans1 = 1e9+7;
    else
        ans1 = a1 + a2 + a3;
    a1 = djikstra(1,o2);
    a2 = djikstra(o2,o1);
    a3 = djikstra(o1,a);
    if (a1 == 1e9+7 || a2 == 1e9+7 || a3 == 1e9+7)
        ans2 = 1e9+7;
    else
        ans2 = a1 + a2 + a3;
    int aaa = min(ans1,ans2);
    if (aaa == 1e9+7)
        cout << "-1";
    else
        cout << aaa;
    //
    return 0;
}