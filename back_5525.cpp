#include <iostream>
#include <string>

using namespace std;



int main()
{
    string st;
    int a, b;
    int sum = 0;

    cin >> a >> b;
    cin >> st;
    for (int i = 0; i < st.size() -2; i++)
    {
        if (st[i] == 'I')
        {
            for (int j = 0; j < a; j++)
            {
                if (!(st[i + 1 + (j * 2)] ==  'O' && st[i + 2 + (j * 2)] == 'I'))
                    break;
                if (j == a - 1)
                {
                      sum++;
                    i++;
                }
            }
        }
    }
    cout << sum;
    return 0;
}