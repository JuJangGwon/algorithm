#include <iostream>

using namespace std;

int n;
int b;
int parent[201];

int getparent(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = getparent(parent[a]);
}
void unionparent(int a,int b)
{
    a = getparent(a);
    b = getparent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}
bool findparent(int a,int b)
{
    a = getparent(a);
    b = getparent(b);
    if (a == b) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> n >> b;
    for (int i = 1; i<= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            cin >> t;
            if (t == 1)
            {
                unionparent(i,j);
                unionparent(j,i);
            }
        }
    }
    int a;
    cin >> a;
    int city = getparent(a);
    for (int i = 2; i <= b; i++)
    {
        cin >> b;
        if (!getparent(b) != city)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}