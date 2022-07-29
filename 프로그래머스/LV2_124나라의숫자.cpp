#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char _124[3] = {'4','1','2'};
    
    while (n > 0)
    {
        answer = _124[n%3] + answer;
        n = (n-1) / 3;
    }
    return answer;
}