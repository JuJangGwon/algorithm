#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    for (int i =0 ; i < participant.size();i++)
    {
        m[participant[i]]++;
    }
    for (int i = 0; i < completion.size();i++)
    {
       m[completion[i]]--;
    }
    
    map<string,int>::iterator it;
    
    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->second!=0)
            return it->first;
    }
    return "0";
}