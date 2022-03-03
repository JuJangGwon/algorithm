#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    int temp_x;
    int temp_y;

    cin >> a >> b;
    temp_x = a / 100;
    temp_y = a % 10;
    a = a % 100;
    a = a - (a % 10);
    a = a + (temp_y * 100) + temp_x;
    temp_x = b / 100;
    temp_y = b % 10;
    b = b % 100;
    b = b - (b % 10);
    b = b + (temp_y * 100) + temp_x;
    if (a > b)
        cout << a;
    else
        cout << b;
    return 0;
}