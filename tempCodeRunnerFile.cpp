#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2111111111

using namespace std;

vector<pair<int, pair<int,int> > > map;

int parent[100001];

int findparent(int x) 
{
    if(parent[x] == x) return x;
    return parent[x] = findparent(parent[x]);
}

void unionparent(int a, int b) 
{
    a = findparent(a);
    b = findparent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int sameparent(int a, int b)
{
    a = findparent(a);
    b = findparent(b);

    if(a == b) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    vector<int> weight;
    int n, m;
    int a, b, c;
    int start, end;
    int ans = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        map.push_back(make_pair(c, make_pair(a, b))); 
        map.push_back(make_pair(c, make_pair(b, a)));
    }

    cin >> start >> end;
    sort(map.begin(), map.end(), greater<pair< int,pair<int,int> > > ());

    for(int i = 0 ; i < map.size() ; i++) 
    {
        int node1 = map[i].second.first;
        int node2 = map[i].second.second;
        int cost = map[i].first;
        unionparent(node1, node2);
        if(sameparent(start, end))
        {
            cout << cost;
            break;
         } 
    }
    return 0;
}