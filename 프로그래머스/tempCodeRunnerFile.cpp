#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    int input = 0;
    cin >> input;
    for (int n = 0; n < input; n++)
    {
        stack<char> c;
        string str;

        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
                c.push(str[i]);

            else if (str[i] == ')')
            {
                if (c.empty())
                {
                    c.push('a');
                    break;
                }
                else
                    c.pop();
            }
        }

        if (!c.empty())
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
    }
}