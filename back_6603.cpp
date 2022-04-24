#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int result[7];
bool used[50];
vector<int> v;
int a, b;

void dfs(int c, int d)
{
    if (d == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for (int i = c; i < a; i++)
    {
        if (!used[v[i]])
        {
            used[v[i]] = true;
            result[d] = v[i];
            dfs(i+1, d + 1);
            used[v[i]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
    cin >> a;
    if (a == 0)
    {
        return 0;
    }
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        v.push_back(b);
    }
    dfs(0,0);
    memset(used,false,50);
    v.clear();
    cout << "\n";
    }
    return 0;
}