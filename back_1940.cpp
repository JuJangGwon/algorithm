#include <iostream>
#include <algorithm>

using namespace std;

int map[15001];
int n, m, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i =0; i < n; i++)
    {
        cin >> map[i];
    }
    sort(map,map+n);

    int pivot1=0;
    int pivot2= n-1;

    while(pivot1 < pivot2)
    {
        if (map[pivot1] + map[pivot2] == m)
        {
            pivot1++;
            pivot2--;
            result++;
        }
        else if(map[pivot1] + map[pivot2] > m)
        {
            pivot2--;
        }
            else if(map[pivot1] + map[pivot2] < m)
        {
            pivot1++;
        }
    }
    cout << result;
}