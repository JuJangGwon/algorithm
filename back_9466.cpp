#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int t,a,b;

int map[100001];
int bmap[100001];
int vv[100001];

int counts = 0;

void dfs(int i)
{
    if (bmap[i] == -1 || vv[i] == 1)
    {
        return ;
    }
    if (bmap[i] == 0)
    {
        bmap[i] = 1;
    }
    else if (bmap[i] == 1)
    {
        counts++;
        vv[i] = 1;
    }
    dfs(map[i]);
    bmap[i] = -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    for (int tt = 1; tt<= t; tt++)
    {
        counts = 0;
        memset(map,0,sizeof(map));
        memset(bmap,0,sizeof(bmap));
        memset(vv,0,sizeof(vv));
        cin >> a;
        for (int i = 1; i<= a; i++)
        {
            int o;
            cin >> o;
            map[i]=o;
        }
        for (int i = 1; i <= a; i++)
        {
            if (!bmap[i])
            {
                dfs(i);
            }
        }     
        cout << a - counts << "\n";
    }

}