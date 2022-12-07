#include <iostream>

using namespace std;

int main()
{
    int sum =0;
    int result = 0;
    int a[8];
    for (int i =0; i < 8; i++)
        cin >> a[i];
    for (int i =0; i < 4; i++)
    {
        sum -= a[i*2];
        sum += a[i*2+1];
        result = max(sum, result);
    }
    cout << result;
}