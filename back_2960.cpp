#include <iostream>

using namespace std;

int main()
{
    int v[1001];
    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = 1 ; i <= a; i++)
        v[i] = false;
    for (int i = 2; i <= a; i++)
    {
        for (int j = 1; j * i <= a; j++)
        {
            if (v[i*j] == false)
            {
                v[i*j] = true;
                sum++;
                if (sum == b)
                {
                    cout << i * j;
                    break;
                }
            }
        }
    }
    return 0;
}