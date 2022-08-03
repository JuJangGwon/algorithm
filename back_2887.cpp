#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <pair<int,int > > xyz[3];                  //  행성 좌표 담는 변수 / (x or y or z , 몇번째인지)
vector <pair<int,pair<int,int> > > planet;        // 정렬하여 거리가 적은 행성 담는 함수 (거리, n번째와 n+1번째)
int n;
int parent[100001];
int result;
int findparent(int x)       // 연결된 부모 찾는 함수 
{
    if (parent[x] == x) return x;
    return parent[x] = findparent(parent[x]);
}
void unionparent(int x, int y)  // 묶어 주는 함수
{
    x = findparent(x);
    y = findparent(y);
    if (x < y)
        parent[y] = x;
    else if (x > y)
        parent[x] = y;
}
int sameparent(int x, int y)    // 부모가 같은지 확인하는 함수 
{
    x = findparent(x);
    y = findparent(y);
    if (x == y)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)             // 벡터에 x, y , z  각각 위치와 몇번째 인지 담아주기
    {
        int x, y , z;
        cin >> x >> y >> z;
        xyz[0].push_back(make_pair(x,i));
        xyz[1].push_back(make_pair(y,i));
        xyz[2].push_back(make_pair(z,i));
        parent[i] = i;
    }
    for (int i = 0; i < 3; i++)           // 정렬되면 거리가 오름차순으로 비슷한거끼리 나열된다.
        sort(xyz[i].begin(),xyz[i].end());
    for (int i = 0; i < n-1; i++)        // 최종적으로 planet 벡터에 정렬된 xyz 벡터의 n번째와 n+1번째 거리와 몇번째인지 각각 넣어주기
    {
        planet.push_back(make_pair(abs(xyz[0][i].first - xyz[0][i+1].first),make_pair(xyz[0][i].second,xyz[0][i+1].second)));
        planet.push_back(make_pair(abs(xyz[1][i].first - xyz[1][i+1].first),make_pair(xyz[1][i].second,xyz[1][i+1].second)));
        planet.push_back(make_pair(abs(xyz[2][i].first - xyz[2][i+1].first),make_pair(xyz[2][i].second,xyz[2][i+1].second)));
    }
    sort(planet.begin(),planet.end());  // 정렬
    for (int i = 0; i < planet.size(); i++)
    {
        if (!sameparent(planet[i].second.first,planet[i].second.second))   // 부모가 같지 않으면 연결되지 않은것, 연결해주기
        {
            result += planet[i].first;
            unionparent(planet[i].second.first,planet[i].second.second);
        }
    }
    cout << result;
    return 0;
}