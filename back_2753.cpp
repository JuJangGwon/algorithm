#include <iostream>

using namespace std;

int main(void)
{
    int i;
    char d;

    if (i % 4 == 0)
    {
        if (i % 100 == 0)
        {
            if (i % 400 == 0)
                cout << "1";
            else
                cout << "0";
        }
        else
            cout << "1";
    }
    else
        cout << "0";
    return 0;
}