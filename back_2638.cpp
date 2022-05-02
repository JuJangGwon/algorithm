#include <iostream>

using namespace std;

int a, b;
int map[101][101];

int main()
{
    cin >> a >> b;
    // for (int i = 1; i <= a; i++)
    // {
    //     for (int j = 1; j <= b; j++)
    //     {
    //         cin >> map[i][j];
    //     }
    // }
    map[4][4] = 1;
    map[4][5] = 2;
    map[3][4] = 1;
    map[5][5] = 1;
    map[5][6] = 1;
    for (int i = 1; i <= a; i++)
    {
        for (int j =1 ; j<= b; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}