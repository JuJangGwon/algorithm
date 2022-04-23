#include <iostream>
#include <vector>

using namespace std;

vector <int> v[2001];

int n,m;
bool ok = false;
bool used[2001];

void dfs(int num1, int num2)
{
    if (num2 == 4)
    {
        ok = true;
        return ;
    }
    for (int i = 0; i < v[num1].size(); i++)
    {
        if (!used[v[num1][i]])
        {
            used[v[num1][i]] = true;
            dfs(v[num1][i],num2 + 1);
            used[v[num1][i]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i,0);
    }    
    cout << ok;

    return 0;
}