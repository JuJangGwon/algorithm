#include <iostream>

using namespace std;

int main()
{
    int x, sum = 0;
    cin >> x;

    for (int i =0; i < 7; i++)
    {
        if (x & (1 << i))
            sum++;
    }
    cout << sum;
}