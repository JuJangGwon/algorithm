#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char> stack;
    string s;
    int result = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (!stack.empty())
                while (stack.top() == ')')
                    stack.pop();
            stack.push('(');
        }
        else
        {
            if (s[i - 1] == '(')
            {
                stack.pop();
                result += stack.size();
            }
            else
            {
                result += 1;
                stack.pop();
            }
        }
    }
    cout << result;
    return 0;
}