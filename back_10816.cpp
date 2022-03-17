#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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
        int num;
        cin >> num;
        cout << upper_bound(a, a + x, num) - lower_bound(a, a+x, num) << " ";
    }
    return 0;
}