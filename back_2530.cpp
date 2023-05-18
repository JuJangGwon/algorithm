#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, result;
    cin >> a >> b >> c >> d >> e;
    result = (a * a + b * b + c * c + d * d + e * e) % 10;
    cout << result;

    return 0;
}