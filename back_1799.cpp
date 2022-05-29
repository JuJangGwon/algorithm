#include <iostream>

using namespace std;

int map[11][11];
int a;
int m;
bool left[21];
bool right[21];

int check()
{

}

void dfs(int num,int b, int c)
{
    m = max(num,m);
    for (int i = b; i <= a; i++)
    {
        for (int j = c; j <= a; j++)
        {
            if (map[i][j] == 1)
            {
                map[i][j] = 2;
                dfs(num+1,i,j);
                map[i][j] = 1;
            }
        }
    }
}

int main()
{
    cin >> a;
    for (int i = 1; i<= a; i++)
    {
        for(int j = 1; j <= a; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << m;
}