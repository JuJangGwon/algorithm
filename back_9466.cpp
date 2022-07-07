#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int t,a,b;

int map[100001];
int bmap[100001];
int counts = 0;

void dfs(int i)
{
    bmap[i]++;
    if (bmap[i] == 3)
    {
        return ;
    }
    else if (bmap[i] <= 2)
    {
        dfs(map[i]);
    }
    if (bmap[i] < 2)
    {
        bmap[i] = 0;
        return ;
    }
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
        for (int i = 1; i <= a;i++)
        {
            if (bmap[i] == 0)
            {
                counts++;
            }
        }
        cout << counts << "\n";
    }

}