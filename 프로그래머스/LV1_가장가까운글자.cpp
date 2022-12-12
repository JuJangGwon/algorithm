#include <string>
#include <vector>

int c[26];

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for (int i =0; i < s.size();i++)
    {
       if (c[s[i]-'a'] == 0)
       {
           c[s[i]-'a'] = i+1;
           answer.push_back(-1);
       }
        else
        {
            answer.push_back((i+1)- c[s[i]-'a']);
            c[s[i]-'a'] = i+1;
        }
    }
    return answer;
}