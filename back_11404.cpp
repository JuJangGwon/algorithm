#include <iostream>
#include <algorithm>

using namespace std;

int maxx = 99999999;
int city[101][101];

int main()
{
    int n, m;
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
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b],c);
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