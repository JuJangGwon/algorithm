#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int pivot = 0;
    for (int i = 1; i <= 100; i++)
    {
        int num = 0;
        while(progresses[pivot] + (i * speeds[pivot]) >= 100 && progresses.size() > pivot)
        {
            pivot++;
            num++;
        }
        if (num)
        {
            answer.push_back(num);
        }
        if(progresses.size() == pivot)
            break;
    }
    return answer;
}