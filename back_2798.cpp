#include <iostream>

using namespace std;

int main(void)
{
    int num, max, greed;
    int a[100];
    cin >> num >> max;
    greed = 0;

    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < num - 2; i++)
    {
        for (int j = i + 1; j < num - 1; j++)
        {
            for (int x = j + 1; x < num; x++)
            {
                int d = a[i] + a[j] + a[x];
                if (d <= max && d > greed)
                    greed = d;
            }
        }
    }
    cout << greed;
    return (0);
}