#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int j = 0; j < a; j++)
    {
    for (int i = 0; i < j + 1; i++)
    {
        cout << "*";
        }
        cout << "\n";
    }
    for (int j = 0; j < a -1; j++)
    {
        for (int i = a - j - 2; i >= 0; i--)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}