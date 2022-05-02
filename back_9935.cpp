#include <iostream>
#include <stack>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a, b;
    deque<char> st;
    stack<char>reverse;
    int b_size;
    cin >> a >> b;

    b_size = b.size();
    for (int i = 0; i < a.size(); i++)
    {
        st.push_back(a[i]);
        if (a[i] == b[b_size-1])
        {
            int c = b_size-1;
            while(c > -1 && !st.empty() && b[c] == st.back())
            {
                reverse.push(st.back());
                st.pop_back();
                c--;
            }
            if (c == -1)
            {
                while(!reverse.empty())
                {
                    reverse.pop();
                }
            }
            else
            {
                while (!reverse.empty())
                {
                    st.push_back(reverse.top());
                    reverse.pop();
                }
            }
        }
    }
    if (st.empty())
    {
        cout << "FRULA";
    }
    else
    {
        while(!st.empty())
        {
            cout << st.front();
            st.pop_front();
        }
    }
    return 0;
}