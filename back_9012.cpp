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

    cin >> i;
    for (int x = 0; x < i; x++)
    {
        t = true;
        cin >> st;
        for (int y = 0; y < st.size(); y++)
        {
            if (st[y] == '(')
                s.push(st[i]);
            else if (st[y] == ')')
            {
                if(s.size() == 0)
                {
                    t = false;
                    break;
                }
                s.pop();
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