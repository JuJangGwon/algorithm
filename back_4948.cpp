#include <iostream>

using namespace std;


int main()
{
    int a;
    int sum = 0;
    cin >> a;
    bool v[246913];

    for (int i = 0; i <= a * 2; i++)
    {
        v[i] = false;
    }
    v[1] = true;
    for (int i = 2; i < a * 2; i++)
    {
        if (v[i] == true)
            continue;
        for (int j = i * 2; j < a * 2; j += i)
        {
            v[j] = true;
        }
    }
    for (int i = a + 1; i < a* 2; i++)
    {
        if (v[i] == false)
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}