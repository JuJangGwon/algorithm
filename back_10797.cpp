#include <iostream>

using namespace std;

int main()
{
    
    int i;
    int a[5];
    cin >>i;
    for (int v = 0; v < 5; v++)
        cin >> a[v];
    int count = 0;
    for (int v = 0; v < 5; v++)
    {
        if (a[v] == i)
            count++;
    }
    cout << count;
    return 0;
}