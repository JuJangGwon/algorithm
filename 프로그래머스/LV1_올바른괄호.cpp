#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> c;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            c.push('(');
        else
        {
            if (c.empty())
            {
                return false;
            }
            else if (c.top() == ')')
            {
                return false;
            }
            else if (c.top() == '(')
            {
                c.pop();
            }
        }
    }
    if (c.size() > 0)
        return false;
    
    return answer;
}