#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxx, node;
vector<pair<int,int> >v[10001];
bool used[10001];

void clear()
{
    for (int i = 1; i <= n; i++)
    {
        used[i] = false;
    }
}
void dfs(int us,int sum)
{
    used[us] = true;
    if (sum > maxx)
    {
        maxx =sum;
        node = us;
    }
    for (int i = 0; i < v[us].size(); i++)
    {
        if (!used[v[us][i].first])
            dfs(v[us][i].first,sum + v[us][i].second);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c)); 
    }
    dfs(1,0);
    clear();
    dfs(node,0);
    cout << maxx;
    return 0;
}