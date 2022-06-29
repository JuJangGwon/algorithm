#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a;
    int sum = 0;
    cin >> a;
    while (a > 0)
    {
        int b = a % 10;
        sum += pow(b,5);
        a /= 10;
    }
    cout << sum;
    return 0;
}