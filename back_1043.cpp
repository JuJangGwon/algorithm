#include <iostream>
#include <vector>

using namespace std;

int n, m, o, mins = -1;
int parent[51];
vector<int> known;
vector<int> map[51];

int findparent(int a)
{
    if (parent[a] == a) return a;
    return parent[a] = findparent(parent[a]);
}
void unionparent(int a, int b)
{
    a = findparent(a);
    b = findparent(b);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    cin >> o;
    for (int i = 0; i < o; i++)
    {
        int d;
        cin >> d;
        known.push_back(d);
    }

    //
    for (int i = 0; i< m; i++)
    {
        int a,piror;
        cin >> a >> piror;
        map[i].push_back(piror);
        for (int j = 2; j <= a; j++)
        {
            int b;
            cin >> b;
            unionparent(piror,b);
            piror = b;
            map[i].push_back(piror);
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        bool cango = true;
        for (int j = 0; j < map[i].size(); j++)
        {
            if (cango == false) break;
            for (int k = 0; k < o; k++)
            {
                if (findparent(map[i][j]) == findparent(known[k]))
                {
                    cango = false;
                    break;
                }
            }
        }
        if (cango == false)
        {
            sum++;
        }
    }
    cout << m - sum;
    return 0;
}