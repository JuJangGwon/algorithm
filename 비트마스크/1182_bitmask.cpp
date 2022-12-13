#include <iostream>

using namespace std;

int main()
{
    int bit = 0;
    int cnt = 0;
    int arr[21];

    int a, b;
    cin >> a >> b;
    for (int i =0 ;i < a; i++)
    {
        cin >> arr[i];
    }
    for (int i =1; i < (1 << a); i++)
    {
        int sum = 0; 

        for (int k = 0; k < a;k++)
        {
            if (i & (1 << k))
            {
                sum += arr[k];
            }
        }
        if (sum == b)
            cnt++;
    }
    cout << cnt;
    return 0;
}