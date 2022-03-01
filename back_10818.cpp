#include <iostream>

using namespace std;

int main(void)
{
    int min = 1000001;
    int max = -1000001;
    int num;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int d;
        cin >> d;
        if (d <= min)
            min = d;
        if (d >= max)
            max = d;
    }
    cout << min << " " << max;
 }