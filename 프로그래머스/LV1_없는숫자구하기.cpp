#include <string>
#include <vector>

using namespace std;

bool num[10];

int solution(vector<int> numbers) {
    int answer = 0;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        num[numbers[i]] = true;
    }
    for (int i =0; i < 10; i++)
    {
        if (num[i] == false)
            answer += i;
    }
    return answer;
}