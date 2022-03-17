#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a;
    int b[1000];
    long long m = 0;
    long long sum = 0;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b[i];
    }
    sort(b, b + a);
    for (int i = 0; i < a; i++)
    {
        m += b[i];
        sum += m;
    }
    cout << sum;

    return 0;
}