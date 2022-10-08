#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    for (int i = 0 ; i < arr.size(); i++)
    {
        if(st.empty() || st.top() != arr[i])
        {
            answer.push_back(arr[i]);
            st.push(arr[i]);
        }
    }

    return answer;
}