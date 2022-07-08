#include <iostream>

using namespace std;

int n, m;
int map[1000001];

int getparent(int a)
{
    if (map[a] == a)    return a;
    return map[a] = getparent(map[a]);
}
void unionparent(int a, int b)
{
    a = getparent(a);
    b = getparent(b);
    if (a > b)
        map[a] = b;
    else
        map[b] = a;
 }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i<= n; i++)
        map[i] = i;
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a == 0)
        {
            unionparent(b,c);
        }
        else
        {
            if (getparent(b) == getparent(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}