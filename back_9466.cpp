#include <iostream>

using namespace std;

int t,a,b;
int map[100001];
bool bmap[100001];

void dfs(int i)
{
    
}

int main()
{
    cin >> t;
    for (int tt = 1; tt<= t; tt++)
    {
        cin >> a;
        for (int i = 1; i<= a; i++)
        {
            cin >> map[i];
        }
        for (int i = 1; i <= a; i++)
        {
            if (!map[i])
            {
                bmap[map[i]] = true;
                dfs(map[i]);
            }
        }
    }
    
}