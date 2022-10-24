#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int i =0; i < s.size()-1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if((int)s[i] < (int)s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    return s;
}