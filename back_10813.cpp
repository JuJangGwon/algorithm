#include <iostream>

using namespace std;

int map[101];

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i <= 100; i++)
    {
        map[i] = i;
    }
    for (int i =0; i < m; i++)
    {
        int x,y; 
        cin >> x >> y;
        int temp = map[x];
        map[x] = map[y];
        map[y] = temp; 
    }
    for (int i =0; i< n; i++)
    {
        cout<< map[i+1] << " ";
    }
}