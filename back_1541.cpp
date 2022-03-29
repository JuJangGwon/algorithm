#include <iostream>
#include <string>

using namespace std;

int main()
{
    int sum = 0;
    bool a = false;
    string str;
    cin >> str;
    for (int i = 0; i <str.size(); i++)
    {
        int d = 0;
        while (str[i] != '-' && str[i] != '+' && i < str.size())
        {
            d *= 10;
            d += str[i] - 48;
            i++;
        }
        //cout << d;
        if (a == false)
            sum += d;
        else if (a == true)
        {
            sum -= d;
        }
        if (str[i] == '-')
            a = true;
    }
    cout << sum;
    return 0;
}