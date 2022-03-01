#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int i;
    int combo;
    int sum;
    string str;

    cin >> i;
    for (int j = 0; j < i; j++)
    {
        cin >> str;
        combo = 1;
        sum = 0;
        for (int x = 0; x < str.size(); x++)
        {
            if (str[x] == 'O')
                sum += combo++;
            else
                combo = 1;
        }
        cout << sum << endl;
    }
    return 0;
}