#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;

int map[1001];
int tmap[1001];
int result[1001];
vector<int> v[1001];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        int piror = 0;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            if (j != 0)
            {
                v[piror].push_back(b);
                tmap[b]++;
            }
            piror = b;
        }
    }
    //
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (tmap[i] == 0)
            q.push(i);
    }
    for (int i = 1;i <=n; i++)
    {
        if (q.empty())
        {
            cout << "0";
            return 0;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for (int j = 0; j < v[x].size(); j++)
        {
            int y = v[x][j];
            tmap[y]--;
            if(tmap[y] == 0)
            {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << "\n";
    }
    return 0;
}