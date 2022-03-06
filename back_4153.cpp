#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;

    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c== 0)
            break;
        if (c < a)
        {
            int temp = a;
            a = c;
            c = temp;
        }
        if (c < b)
        {
            int temp = b;
            b = c;
            b = temp;
        }
        if ((a * a) + (b * b) == (c * c))
            cout << "right" << endl;
        else 
            cout << "wrong" << endl;
    }
    return 0;
}