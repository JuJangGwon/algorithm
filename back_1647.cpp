#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxi;
vector<pair<int,int> > map[100001];
bool bmap[100001];
priority_queue<pair<int ,int> , vector<pair<int,int> >, greater<pair<int,int> > >pq;
int sum = 0;

void prim(int a)
{
    bmap[a] = true;
    for(int i = 0; i < map[a].size(); i++)
    {
        if(!bmap[map[a][i].second])
        {
            pq.push(make_pair(map[a][i].first,map[a][i].second));
        }
    }
    while(!pq.empty())
    {
        pair<int,int>pai = pq.top();
        pq.pop();
        if(!bmap[pai.second])
        {
            maxi = max(maxi,pai.first);

            sum +=pai.first;
            prim(pai.second);
            return;
        }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        int c,d,f;
        cin >> c >> d >> f;
        map[c].push_back(make_pair(f,d));
        map[d].push_back(make_pair(f,c));
    }
    prim(1);
    cout << sum - maxi;
}