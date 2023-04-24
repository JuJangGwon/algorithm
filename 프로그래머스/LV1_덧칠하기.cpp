#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    vector<pair<int, int> > v;
    int start = section[0];
    int end = start + m - 1;
    v.push_back({start, end});

    answer = 1;

    for (int i = 0; i < section.size(); i++)
    {
        if (section[i] > end)
        {
            answer++;
            start = section[i];
            end = start + m - 1;
        }
    }
    return answer;
}