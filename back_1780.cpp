#include <iostream>

using namespace std;

int c1, c2 ,c3;
int map[2187][2187];

void check(int x, int y, int size)
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (map[i][j] != map[x][y])
            {
                check(x,               y,           size / 3);
                check(x + size /3,     y,           size / 3);
                check(x + size /3 * 2, y,           size / 3);

                check(x,               y + size /3, size /3);
                check(x + size /3,     y + size /3, size / 3);
                check(x + size /3 * 2, y + size /3, size / 3);

                check(x,               y + size /3 * 2 ,size /3);
                check(x + size /3,     y + size /3 * 2, size / 3);
                check(x + size /3 * 2, y + size /3 * 2, size / 3);
                return ;
            }
        }
    }
    if (map[x][y] == -1)
        c1++;
    else if (map[x][y] == 0)
        c2++;
    else if (map[x][y] == 1)
        c3++;
    return ;
}

int main()
{
    int a;
    cin >> a;
    for (int x = 0; x < a; x++)
    {
        for (int y = 0; y < a; y++)
        {
            int o;
            cin >> o;
            map[x][y] = o;
        }
    }
    check(0,0,a);
    cout << c1 << endl << c2 << endl << c3;
    return 0;
}