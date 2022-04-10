#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool vv[1001];

void DFS(int idx)
{
    cout << idx << " ";
    for (int i = 1; )
}

int main()
{
    stack<int> st;
    int a, b, c, start;
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
    return 0;
}