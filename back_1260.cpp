#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

int main()
{
    stack<int> st;
    cin >> a >> b >>c;

    for (int i = 0; i < b; i++)
    {
        int o, oo;
        cin >> o >> oo;
        v[o].push_back(oo);
    }
    for  (int i = 1; i < b; i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    DFS(c);
    return 0;
}