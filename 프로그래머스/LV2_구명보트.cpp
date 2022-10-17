#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int pivot =0;
    int head = people.size() - 1;
    while (pivot <= head)
    {
        if (people[pivot] + people[head] <= limit)
        {
            answer++;
            head--;
            pivot++;
        }
        else
        {
            answer++;
            head--;
        }
        
    }
    return answer;
}