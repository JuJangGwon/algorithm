#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxx, node;
vector<pair<int,int> >v[100001];
bool used[100001];

void clear()
{
    for(int i = 1; i <= n; i++)
    {
        used[i] = false;
    }
}
void dfs(int now, int sum)
{
    if (maxx < sum)
    {
        node = now;
        maxx =sum;
    }
    for (int i = 0; i < v[now].size(); i++)
    {
        if(!used[v[now][i].first])
        {
            used[v[now][i].first] = true;
            dfs(v[now][i].first,sum + v[now][i].second);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        while (1)
        {
            cin >> b;
            if (b == -1)
                break;
            else
            {
                cin >> c;
                v[a].push_back(make_pair(b,c));
                v[b].push_back(make_pair(a,c));
            }
        }
    }
    used[1] =true;
    dfs(1,0);
    clear();
    used[node] =true;
    dfs(node,0);
    cout << maxx;
    return 0;
}