#include <iostream>
#include <string>

using namespace std;

int check(string o)
{
    for (int i = 0; i< o.size() - 2; i++)
    {
        if (o[i] == '6' && o[i + 1] == '6' && o [i + 2] == '6')
            return (1); 
    }
    return 0;
}
int main(void)
{
    int a;
    int count = 0;
    int d = 666;
    string v;
    cin >> a;

    while (1)
    {
        v = to_string(d);
        if (check(v))
            count++;
        if (a == count)
        {
            cout << d;
            break;
        }
        d++;
    } 
    return 0;
}