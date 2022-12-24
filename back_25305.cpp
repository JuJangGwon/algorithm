#include <iostream>
#include <algorithm>

using namespace std;

int map[1001];

int main()
{
    int n,m;
    cin >> n >> m;  
    for (int i =0; i < n;i++)
    {
        cin >> map[i];
    }
    sort(map,map+n,greater<int>());
    cout << map[m-1];

    return 0;
}