#include <iostream>

using namespace std;

int main(void)
{
    int i;
    int x;
    int a[7];

    //1234567

    cin >> i;
    x = i;
    for(int j = 0; j < 7; j++)
    {
        i += x % 10;
        x = x / 10;
    }
    cout << i;

    return 0;
}