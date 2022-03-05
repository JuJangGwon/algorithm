#include <iostream>

using namespace std;

int main()
{
    bool i_[1001];
    int i = 0;

    for (int i = 0; i <= 1000; i++)
    {
        i_[i] = false;
    }
    i_[0] = true;
    i_[1] = true;

    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 2; j * i <= 1000; j++)
        {
            i_[j*i] = true;
        }
    }
    
    int v;
    int count = 0;
    int vv[100];

    cin >> v;
    for (int i = 0; i< v; i++)
    {
        cin >> vv[i];
    }
    for (int i = 0; i <v; i++)
    {
        if (i_[vv[i]] == false)
            count++;
    }
    cout << count;
    return 0;
}