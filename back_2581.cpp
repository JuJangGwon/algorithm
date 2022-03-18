#include <iostream>

using namespace std;

int main()
{
    bool a[10001];
    int min, max;
    int c = 0;
    int sum = 0;
    cin >> min >> max;
    a[1] = false;

    for (int i = 2; i <= max; i++) {
		a[i] = true;
	}
    for (int i =2 ; i < max; i++)
    {
        for (int j = 2; j * i <= max; j++)
        {
            a[i*j] = false;
        }
    }
    for (int i = min; i <= max; i++)
    {
        if (a[i] == true)
        {
            if (c == 0)
                c = i;
            sum += i;
        }
    }
    if (c == 0)
        cout << "-1";
    else
        cout << sum << endl << c;
    return 0;
}