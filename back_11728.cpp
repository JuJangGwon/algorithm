#include <iostream>

using namespace std;

int arr_n[1000001];
int arr_m[1000001];

int result[2000002];

int pivot_n, pivot_m;

int main()
{
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i =0; i < n; i++)
    {
        cin >> arr_n[i];
    }
    for (int i =0; i < m; i++)
    {
        cin >> arr_m[i];
    }
    int idx = 0;
    while (pivot_n < n && pivot_m < m)
    {
        if(arr_m[pivot_m] >= arr_n[pivot_n])
        {
            result[idx++] = arr_n[pivot_n++];
        }
        else
        {
            result[idx++] = arr_m[pivot_m++];
        }
    }
    while (pivot_n < n)
    {
         result[idx++] = arr_n[pivot_n++];
    }
    while (pivot_m < m)
    {
         result[idx++] = arr_m[pivot_m++];
    }
    for (int i =0; i < n+m; i++)
    {
        cout << result[i] << " ";
    }
}