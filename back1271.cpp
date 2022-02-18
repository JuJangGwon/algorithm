#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a;
    int b = 0;

    cin >> a;

    for(int i = 0; i< a.length(); i++)
    {
        b *= 16;
        if (a[i] >= 'A' && a[i] <= 'F')
        {
            b += a[i] - 'A' + 10 ;
        }
        else if (a[i] >= '0' && a[i] <= '9')
        {
            b += a[i] - '0';
        }

    }
    cout << b << endl;
    return 0;
}
