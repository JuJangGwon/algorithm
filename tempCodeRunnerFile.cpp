#include <iostream>

using namespace std;

#define maxx 10000001

int city[101][101];

int n, m, a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                city[i][j] = maxx;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (city[a][b] > b)
        {
            city[a][b] = c;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city[i][j] == maxx)
                cout << "0 ";
            else
                cout << city[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

