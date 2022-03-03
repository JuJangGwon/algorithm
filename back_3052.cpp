#include <iostream>

using namespace std;
int x[10];
int y[10];

int check(int a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a == y[i])
            return 0;
    }
    return 1;
}

int main(void)
{
    int size = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (check(x[i] % 42, size))
        {
            y[size] = x[i]  % 42;
            size++;
        }
    }
    cout << size;
    return 0;
}