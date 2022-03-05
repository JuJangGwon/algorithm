#include <iostream>

using namespace std;

int x[50];
int y[50];

int main(void)
{
    int num;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> x[i] >> y[i];
    }
}