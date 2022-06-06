#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<pair<double,double > > v;
vector<pair<double,int> > star[101];
bool bstar[101];
double ans = 0.0;

void prim(int a)
{
    bstar[a] = true;
    priority_queue<pair<double,int>, vector<pair<double,int> >,greater<pair<double,int> > > pq;
    for (int i = 0; i < star[a].size(); i++)
    {
        if (!bstar[star[a][i].second])
        {
            pq.push(make_pair(star[a][i].first,star[a][i]).second);
        }
    }
    while (!pq.empty())
    {
        pair<double,int> par = pq.top();
        pq.pop();
        if (!bstar[par.second])
        {
            ans+=par.first;
            prim(par.second);
            return;
        }
    }
}

int main()
{
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        double b, c;
        cin >> b >> c;
        v.push_back(make_pair(b,c));
    }
    for (int i = 1; i <= a-1; i++)
    {
        double x = v[i].first;
        double y = v[i].second;
        for (int j = i + 1; j <= a; j++)
        {
            double xx = v[j].first;
            double yy = v[j].second;
            double dist = sqrt(pow(xx-x, 2)+pow(yy-y, 2));
            cout << xx << ", " << yy << " : " << dist << " | ";
            star[i].push_back(make_pair(dist,j));
            star[j].push_back(make_pair(dist,i));
        }
    }
    prim(1);
    cout.precision(3);
    cout << ans;
}