#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int i;
    bool t;
    string st;
    stack<char> s;

    while (1)
    {
        t = true;
        cin >> st;
        if (st[0] == '.')
            break;
        for (int y = 0; y < st.size(); y++)
        {
            if (st[y] == '(' || st[y] == '{' || st[y] == '[')
                s.push(st[i]);
            else if (st[y] == ')')
            {
                if(s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    t = false;
                    break;
                }
            }
            else if (st[y] == ']')
            {
                if(s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    t = false;
                    break;
                }
            }
              else if (st[y] == '}')
            {
                if(s.top() == '{')
                {
                    s.pop();
                }
                else
                {
                    t = false;
                    break;
                }
            }
        }
        if (t == false)
            cout << "NO" << endl;
        else
        {
            if (s.size() > 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        while (!s.empty())
        {
            s.pop();
        }
    }
    return 0;
}