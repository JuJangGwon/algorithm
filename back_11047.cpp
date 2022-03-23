#include <iostream>

using namespace std;

int main()
{
    int v[10];
    int n, m;
    int sum = 0;
    cin >> n >> m;
    for (int i = 0; i< n; i++)
    {
        cin >> v[i];
    }
   
        for (int i = n - 1; i >= 0; i--)
        {
            if (m / v[i] > 0)
            {
                sum += m / v[i];
                m -= v[i] * (m / v[i]);
            }
        }
    cout << sum;
    return 0;
}