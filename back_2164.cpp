#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int x;
    int d;
    queue<int> y;

    cin >> x;
    for (int i = 1;i <= x; i++)
    {
        y.push(i);
    }
    if (y.size() == 1)
        cout << "1";
    else
    {
        while (y.size() > 1)
        {
            y.pop();
            if (y.size() == 1)
                cout << y.front();
            d = y.front();
            y.pop();
            y.push(d);
        }
    }
    return 0;
}