#include <iostream>

using namespace std;

int main()
{
    int d;
    int sum = 0;

    for (int i =0; i< 5; i++)
    {
        cin >> d;
        sum += (d * d);
    }
    cout << sum % 10 << endl;
}