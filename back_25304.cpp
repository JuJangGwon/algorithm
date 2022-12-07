#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int b;
    cin >> b;
    int sum = 0;
    for (int i = 0; i < b; i++)
    {
        int c, d;
        cin >> c >> d;
        sum += (c * d);
    }
    if (sum == a)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}