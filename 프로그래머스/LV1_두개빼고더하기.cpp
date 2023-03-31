#include <string>
#include <vector>

using namespace std;

int map[10001];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i =0 ; i < numbers.size();i++)
    {
        for (int j = i+ 1; j < numbers.size();j++)
        {
            map[numbers[i]+numbers[j]] = true;
        }
    }
    for (int i =0; i<= 10000; i++)
        if (map[i] == true)
            answer.push_back(i);
    return answer;
}