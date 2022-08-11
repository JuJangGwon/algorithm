#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2111111111

using namespace std;

vector<pair<int, pair<int,int> > > map;

int parent[100001];

int findparent(int x)                           // 부모찾기
{
    if(parent[x] == x) return x;
    return parent[x] = findparent(parent[x]);
}

void unionparent(int a, int b)                  // 합치기
{
    a = findparent(a);
    b = findparent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int sameparent(int a, int b)                    // 같은지 체크 
{
    a = findparent(a);
    b = findparent(b);

    if(a == b) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, m;
    int a, b, c;
    int start, end;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) parent[i] = i;                    // 부모 노드 자기자신으로 초기화

    for(int i = 0 ; i < m ; i++) 
    {
        cin >> a >> b >> c;
        map.push_back(make_pair(c, make_pair(a, b))); 
        map.push_back(make_pair(c, make_pair(b, a)));
    }

    cin >> start >> end;
    sort(map.begin(), map.end(), greater<pair< int,pair<int,int> > > ());           // 중량을 기준으로 오름차순정렬하기

    for(int i = 0 ; i < map.size() ; i++) 
    {
        int node1 = map[i].second.first;
        int node2 = map[i].second.second;
        int cost = map[i].first;
        unionparent(node1, node2);
        if(sameparent(start, end))                                              // 쭉 연결 하다가 공장을 가진 섬 2개가 연결됐으면 결과출력
        {
            cout << cost;
            break;
         } 
    }
    return 0;
}