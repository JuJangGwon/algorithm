#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    
    int i;
    int d;
    cin >> i;
    for(int j = 0; j < i; j++)
    {
        cin >> d;
        if (d == 0)
            s.pop();
        else
            s.push(d);
    }
    i = 0;
    for (int j = 0; j < s.size() + 1; j++)
    {
        if (s.size() != 0)
        {
        i += s.top();
        s.pop();
        }
        else
            break;
    }
    cout << i;
}