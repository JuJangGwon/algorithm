#include <iostream>

using namespace std;

int map[128][128];
int blue;
int white;

void divide(int x, int y, int size)
{
    bool bb = map[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (map[i][j] != bb)
            {
                divide(x,y, size /2);
                divide(x + size / 2,y, size /2);
                divide(x,y + size / 2, size /2);
                divide(x + size / 2,y + size/ 2, size /2);
                return ;
            }
        }
    }
    if (bb == false)
        white++;
    else
        blue++;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    divide(0,0,n);
    cout << white << endl << blue;
    return 0;
}