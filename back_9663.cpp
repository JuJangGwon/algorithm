#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
bool map[16][16];
bool bmap[16][16];
int n;
int sum = 0;
vector<pair<int, int> >v[16];



bool check(int x, int y, int c)
{
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <=c; i++)
        {
            map[v[i].front().second][v[i].front]
        }
    }
}

void dfs(int num, int now)
{
    if (num == 8)
    {
        sum++;
        return ;
    }
    for (int i = now; i <= n; i++)
    {
        
    }
}

int main()
{
    cin >> n;

    return 0;
}