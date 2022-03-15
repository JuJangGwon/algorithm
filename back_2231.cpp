#include <iostream>

using namespace std;

int main(void)
{
    int i;
    int x;
    int result = 0;
    int sum;
    cin >> i;

    for (int c = 1 ; c < i; c++)
    {
        x = c;
        sum = c;
        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }
        if (sum == i)
        {
            result = c;
            break;
        }
    }
    cout << result;

    return 0;
}