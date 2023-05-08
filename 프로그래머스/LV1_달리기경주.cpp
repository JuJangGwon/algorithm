#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer = players;
    map<string, int> ma;

    for (int i = 0; i < players.size(); i++)
    {
        ma[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++)
    {
        int pivot = ma[callings[i]];
        int temp = (pivot - 1 + players.size()) % players.size();
        swap(answer[pivot], answer[temp]);
        ma[callings[i]] = temp;
        ma[answer[pivot]] = pivot;
    }

    return answer;
}