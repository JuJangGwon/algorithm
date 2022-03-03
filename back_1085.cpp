#include <iostream>

using namespace std;

int main(void)
{
    int x, y, w, h;
    int min;
    int minn;

    cin >> x >> y >> w >> h;
    if (w - x <= x)
        min = w - x;
    else
        min = x;
    if (h - y <= y)
        minn = h - y;
    else
        minn = y; 
    if (minn > min)
        cout << min;
    else
        cout << minn;
    return (0);
}