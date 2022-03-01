#include <iostream>

using namespace std;

int main(void)
{
    int i, b;

    cin >> i >> b;
    if (i > b)
        cout << ">";
    else if (i < b)
        cout << "<";
    else
        cout << "==";

    return 0;
}