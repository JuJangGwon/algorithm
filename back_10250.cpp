#include <iostream>

using namespace std;

int main()
{
    int a;
    int x, y ,z;

    cin >> a;
    for (int i = 0; i< a; i++)
    {
        cin >> x >> y >> z;
        if (z != 1)
        {
            y = (z % x) * 100 + (z / x + 1);
        }
        else
        {
            y = (z % x + 1) * 100 + (z / x);
        }
        cout << y << "\n"; 
    }
    return 0;
}