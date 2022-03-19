#include <iostream>

using namespace std;

int main()
{
    int c, a, b;

    cin >> c;
    for (int i = 1; i <= c; i++)
    {
        cin >> a >> b;
        cout << "Case #"<< i << ": " <<a << " + " << b << " = "<< a + b <<"\n"; 
    }   
    return 0;
}