#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a;
    string d;

    cin >> a;
    for (int i =0 ; i< a; i++)
    {
        cin >> d;
        cout << d[0] - 48 + d[2] - 48 << "\n";
    }
    return 0;
}