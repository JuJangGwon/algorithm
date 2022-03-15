#include <iostream>

using namespace std;

int factor(int i)
{
    if (i == 0 || i == 1)
        return 1;
    return i * factor(i - 1);
}

int main()
{
    int i;

    cin >>i;
    cout << factor(i);
    return 0;
}