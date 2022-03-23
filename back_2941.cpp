#include <iostream>
#include <string>

using namespace std;

string str[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int check(string sv, int o)
{
    for (int i = 0; i < 8; i++)
    {
        int j = 0;
        while (sv[o + j] == str[i][j])
        {
            j++;
            if (!str[i][j])
            {
                return j;
            }
        }
    }
    return 0;
}

int main()
{
    int sum = 0;
    string st;
    cin >> st;

    for (int i = 0; i < st.size(); i++)
    {
        int v = check(st, i);
        if (v > 0)
        {
            i += (v - 1);
        }
        sum++;
    }
    cout << sum;
    return 0;
}