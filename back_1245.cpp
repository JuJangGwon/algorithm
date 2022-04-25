#include <iostream>

using namespace std;

int map[101][71];
bool used[101][71];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs()
{
    int max = 0;
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a;
            cin >> a;
            map[i][j] = a;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!used[i][j])
            {

            }
        }
    }
}