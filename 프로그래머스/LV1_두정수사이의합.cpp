#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    answer += a;
    while (a!=b)
    {
        if (a>b)
        {
            a--;
        }
        else
            a++;
        answer += a;
    }
    return answer;
}