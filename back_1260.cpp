#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int a, b, c, start;

vector<int> v[1001];
bool vv[1001];

void DFS(int idx)
{
        cout << idx << " ";
        vv[idx] = true;

    for (int i = 1; i <= a; i++)
    {
        if (!vv[i])
        {   
            DFS(i);
        }
    }
}
void BFS(int idx)
{
    queue<int> q;
    q.push(idx);
    vv[idx] = true;

    while (!q.empty())
    {
        idx = q.front();
        q.pop();
        cout << idx << " ";
        for (int i = 0; i < v[idx].size(); i++)
        {
            if (vv[v[idx][i]] == false)
            {
                q.push(v[idx][i]);
                vv[v[idx][i]] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;
    cin >> a >> b >>c;

    for (int i = 0; i < b; i++)
    {
        int o, oo;
        cin >> o >> oo;
        v[o].push_back(oo);
        v[oo].push_back(o);
    }
    for  (int i = 1; i <= b; i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    DFS(c);
    memset(vv,false,sizeof(vv));
    cout << "\n";
    BFS(c);

    return 0;
}