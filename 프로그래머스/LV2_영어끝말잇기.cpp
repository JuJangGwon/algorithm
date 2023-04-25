#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;

    map<string, int> dic;
    dic[words[0]]++;
    for (int i = 1; i < words.size(); i++)
    {
        if ((dic.find(words[i]) != dic.end()) || words[i][0] != words[i - 1][words[i - 1].size() - 1])
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        else
        {
            dic[words[i]]++;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}