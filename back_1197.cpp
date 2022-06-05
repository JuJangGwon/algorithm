#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> >v[10001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int, int> > >pq;
bool bv[10001];
int sum;

void prim(int a)
{
    bv[a] = true;
    for (int i =0; i < v[a].size(); i++)
    {
        if(!bv[v[a][i].second])
        {
            pq.push(make_pair(v[a][i].first,v[a][i].second));
        }
    }
    while (!pq.empty())
    {
        pair<int,int> pp = pq.top();
        pq.pop();
        if (!bv[pp.second])
        {
            sum+=pp.first;
            prim(pp.second);
            return ;
        }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
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