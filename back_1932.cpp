#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int arr2[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;
    long long maxx = 0;
    
    cin >> a;
    for (int i = 1; i <=a; i++)
    {
        for (int j =1; j <=i; j++)
        {
            cin >> arr[i][j];
        }
    }
    arr2[1][1] = arr[1][1];
    maxx = (long long)arr2[1][1];
    for (int i = 2; i <= a; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                arr2[i][j] = arr2[i-1][1] + arr[i][1];
            else if (j == i)
                arr2[i][j] = arr2[i-1][j - 1] + arr[i][j]; 
            else
                arr2[i][j] = arr[i][j] + max(arr2[i-1][j - 1], arr2[i-1][j]);
            maxx = max((long long)arr2[i][j], maxx);
        }
    }
    cout << maxx;
}