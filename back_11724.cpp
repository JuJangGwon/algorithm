#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
bool vv[1001];

void dfs(int o)
{
    vv[o] = true;
    for (int i = 0; i < v[o].size(); i++)
    {
        if (vv[v[o][i]] == false)
        {
            dfs(v[o][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= a; i++)
    {
        if (!vv[i])
        {
            dfs(i);
            sum++;
        }
    }
    cout << sum;
    return 0;
}