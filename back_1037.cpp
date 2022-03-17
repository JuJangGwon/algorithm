#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int min = 1000000;
    int max = 0;
    long long sum;
    cin >> a;
    if (a == 1)
    {
        cin >> b;
        cout << b * b;
        return 0;
    }
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        if (b > max)
        {
            max = b;
        }
        if (b < min)
        {
            min = b;
        }
    }
    cout << min * max;
    return 0;
}