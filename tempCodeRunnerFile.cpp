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
        y = (z % x) * 100 + (z / x + 1);
        cout << y << "\n"; 
    }
    return 0;
}