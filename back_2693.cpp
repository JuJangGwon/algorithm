#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[10];
    int b;

    cin >> b;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> a[j];
        }
        sort(a,a + 10);
        cout << a[7] << endl;
    }
    return 0;
}