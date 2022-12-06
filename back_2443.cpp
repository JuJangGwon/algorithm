#include <iostream>

using namespace std;

int main()
{
    int a;
    
    cin >> a;

    for (int i =a-1; i >= 0;i--)
    {
        for (int j =i; j < a-1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i*2 +1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}