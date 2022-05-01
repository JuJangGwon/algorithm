#include <iostream>

using namespace std;
char map[21][21];
bool used[27];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int maxx = 0;

int a, b;
void dfs(int x, int y,int c)
{
    if (maxx < c)
        maxx = c;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && xx <= b && yy >= 1 && yy <= a && !used[map[yy][xx]-'A'])
        {
            used[map[yy][xx]-'A'] = true;
            dfs(xx,yy,c+1);
            used[map[yy][xx]-'A'] = false;
        }
    }
}
int main()
{
    cin >> a >> b;
    for (int i = 1; i<=a;i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> map[i][j];
        }
    }
    used[map[1][1]-'A'] = true;
    dfs(1,1,1);
    cout << maxx;
    return 0;
}