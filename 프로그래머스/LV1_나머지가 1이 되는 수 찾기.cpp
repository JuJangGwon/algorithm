#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;
    while (a != n-1)
    {
        if (n % a ==1)
            break;
        a++;
    }
    answer = a;
    return answer;
}