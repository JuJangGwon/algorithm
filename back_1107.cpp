#include <iostream>
#include <string>

using namespace std;

bool none[10];

int made(int num)
{
    string c = to_string(num);
    int i = 0;
    for (int i = 0 ; i < c.size(); i++)
    {
        i*=10;
       // for (int j = c) 
    }
    return 0;
}

int main()
{
    int sum = 0;
    int now = 100;
    int a,b;
    cin >> a >> b;
    for (int i = 0 ; i < b; i++)
    {
        int c;
        cin >> c;
        none[c] = true;
    }
    while (now != a)
    {
        cout << "**";
    }
    cout << sum;
    return 0;
}