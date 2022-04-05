#include <iostream>

using namespace std;

int sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    
    sum[0] = 0;
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
    {
        int d;
        cin >> d;
        sum[i] = sum[i-1] + d;
    }
    for (int i = 0; i < b; i++)
    {
        int n, m;
        cin >> n >> m;
        cout << sum[m]-sum[n -1] << "\n";
    }
    return 0;
}