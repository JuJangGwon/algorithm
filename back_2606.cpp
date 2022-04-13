#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int comnum, b, sum = 0;
vector<int> v[101];
bool vv[101];

void dfs(int a)
{
    for (int i = 0; i < v[a].size(); i++)
    {
        if (!vv[v[a][i]])
        {
            sum++;
            vv[v[a][i]] = true;
            dfs(v[a][i]);
        }
    }
}

int main()
{
    cin >> comnum >> b;
    for (int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vv[1] = true;
    dfs(1);
    cout << sum;
    return 0;
}