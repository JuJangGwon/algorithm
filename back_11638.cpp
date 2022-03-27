#include <iostream>

using namespace std;

int main()
{
    int a;

    cin >> a;
    if (a == 1)
        return 0;
    for (int i = 2; i <= a; i++)
    {
        while (a % i == 0)
        {
            cout << i << "\n";
            a /= i;
        }
    }
    return 0;
}