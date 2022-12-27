#include <iostream>
#include <algorithm>

using namespace std;

int map[1000001];


bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i =0; i < n; i++)
    {
        cin >> map[i];
    }
    sort(map,map+n,compare);
    for (int i =0; i< n;i++)
    {
        cout << map[i] << "\n";
    }
}
