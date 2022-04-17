#include <iostream>

using namespace std;

int map[101][101];

int main()
{
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                map[i][j] = 99999;
        }
    }

    for (int k = 1; k <= a; k++)
    {
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= a ;j++)
            {
                map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
            }
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j =1; j <= a; j++)
        {
            if (map[i][j] == 99999)
                cout << "0 ";
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

