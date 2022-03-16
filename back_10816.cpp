#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x, y;
    int a[500000];
    int b[500000];

    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }
    sort(a, a + x);
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < y; i++)
    {
        int sum = 0;
        int pivot = x / 2;
        while ()
        {

        }
    }
    return 0;
}