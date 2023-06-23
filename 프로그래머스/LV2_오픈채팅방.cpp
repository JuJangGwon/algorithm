#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;
    vector<pair<string,string> >p;
    for (int i = 0; i < record.size(); i++)
    {   
        stringstream ss(record[i]); 
        string token;
        string str[3];
        int index= 0;
        while (ss >> token)
        {
            str[index++] = token;
        }
        if (str[0] != "Leave")
            m[str[1]] = str[2];
        p.push_back({str[0],str[1]});
    }
    for (int i = 0; i < p.size();i++)
    {
        if (p[i].first == "Enter")
        {
            string temp =  m[p[i].second] +"님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if(p[i].first == "Leave")
        {
            string temp =  m[p[i].second] +"님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    return answer;
}