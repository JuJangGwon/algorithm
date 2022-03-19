#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int _a =1;
    int _b = 1;
    int _c = 1;
    int cas = 1 ;
    cin >> a >> b >> c;
    while (1)
    {
        if (a == _a && b == _b && c == _c)
        {
            cout << cas;
            return 0;
        }
        cas++;
        _a++;
        _b++;
        _c++;
        if (_a == 16)
            _a = 1;
        if (_b == 29)
            _b = 1;
        if (_c == 20)
            _c =1;
    }
    return 0;
}