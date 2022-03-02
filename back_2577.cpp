#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int a, b, c;
    int d;
    int sum;
    string str;
    cin >> a >> b >> c;
    sum = a * b * c;
    str = to_string(sum);

    for (int i = 0; i< 10; i++)
    {
        d = 0;
        for (int j = 0; j <str.size(); j++)
        {
            if (i == str[j] - 48)
                d++;
        }
        cout << d << endl;
    }
    return 0;
}