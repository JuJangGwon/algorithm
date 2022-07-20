#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int shape_x1[4][4] = {{0,0,1,0},{0,1,1,2},{0,0,-1,0},{0,1,1,2}};           // ㅏ ㅗ ㅓ ㅜ  모양                                             
int shape_y1[4][4] = {{0,1,1,2},{0,0,1,0},{0,1,1,2},{0,0,-1,0}};

int a, b, maxx, mmax;
int map[501][501];
bool bmap[501][501];

void shapecheck(int x, int y)    // dfs  ㅗ ㅏ ㅜ ㅓ 체크
{
    for (int j = 0; j < 4; j++)
    {
        mmax = 0;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + shape_x1[j][i];
            int yy = y + shape_y1[j][i];
            if (xx >= 1 && yy >= 1 && xx <= b && yy <= a)
            {
                mmax += map[yy][xx];
            }
            else
            {
                break;
            }
        }
        maxx = max(mmax,maxx);
    }
}

void dfs(int result, int sum, int x, int y)         // 4 모양 체크
{
    if (result == 4)
    {
        maxx = max(maxx,sum);
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && yy >= 1 && xx <= b && yy <= a && !bmap[yy][xx])
        {
            bmap[yy][xx] = true;
            dfs(result+1, sum + map[yy][xx], xx,yy);
            bmap[yy][xx] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            bmap[i][j] = true;
            dfs(1,map[i][j],j,i); 
            bmap[i][j] = false;
            shapecheck(j,i);
        }
    }
    cout << maxx;

    return 0;
}
