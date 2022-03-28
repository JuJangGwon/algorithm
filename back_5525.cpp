#include <iostream>
#include <string>

using namespace std;



int main()
{
    string st;
    int a, b, c;
    int sum = 0;

    cin >> a >> b;
    cin >>   st;
    for (int i = 0; i < st.size() - (2 * a) ; i++)
    {
        c = 0;
        if (st[i] == 'I')
        {
           while (st[i + 1] == 'O' && st[i + 2] == 'I')
           {
             i += 2;
               c++;
                if (a == c)
                {
                    sum++;
                    c--;
                }
           }
        }
    }
    cout << sum;
    return 0;
}
