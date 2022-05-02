#include <iostream>

using namespace std;

int a, b;
int map[101][101];

int main()
{
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> map[i][j];
        }
    }
    return 0;
}