#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    int answer = 0;

    for (int i = 0 ; i < s.size(); i++)
    {
        if (st.empty())
            st.push(s[i]);
        else
        {
            if(st.top() == s[i])
            {
                st.pop();
            }
            else
                st.push(s[i]);
        }
    }
    if (st.empty())
        answer = 1;
    return answer;
}