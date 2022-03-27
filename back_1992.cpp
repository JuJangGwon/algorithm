#include <iostream>

using namespace std;
char map[64][64];

void checker(int x, int y, int size)
{
    char c = map[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j <  y + size; j++)
        {
            if (map[i][j] != c)
            {
                cout << "(";
                checker(x,                  y,                                             size /2);
                checker(x,        y  + size /2,                                  size /2);
                checker(x+ size /2,                  y ,                                 size/ 2);
                checker(x + size /2,        y + size /2,                        size /2);
                cout << ")";
                return ;
            }
        }
    }
    cout << (char)c;
}

int main()
{
    int a;
    cin >> a;

    for (int i =0 ; i< a; i++)
    {
        for (int j =0 ; j < a; j++)
        {
            cin >> map[i][j];
        }
    }
    checker(0,0,a);
    return 0;
}