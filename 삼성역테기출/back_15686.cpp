#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

vector<make_pair<int, int> >chik;
int chicknum;
int map[51][51];
int n;
using namespace std;

int main()
{
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        for (int j =1; j <=n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                chik()
                chicknum++; 
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j<=n; j++)
        {
            if (map[i][j] == 1)
            {
                int minss = 99999999;
                for (int c = 0; c < chicknum; c++)
                {
                    minss = min(minss, abs(i-j) + a);
                }
            }
        }
    }
}