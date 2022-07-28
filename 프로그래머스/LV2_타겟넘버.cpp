#include <string>
#include <vector>

using namespace std;
int targets;
int answers;
int sum = 0;

void dfs(int num, vector<int>numbers)       // 백트래킹
{
    if (num  == numbers.size())
    {
        if (sum == targets)
        {
            answers++;
        }
        return ;
    }
    sum += numbers[num];
    dfs(num+1,numbers);
    sum -= numbers[num] * 2;
    dfs(num+1,numbers);
    sum += numbers[num];
}

int solution(vector<int> numbers, int target) {
    targets = target;
    dfs(0,numbers);
    return answers;
}