#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int x_pivot = 0;
    int y_pivot = 0;
    int now_pivot = 0;

    while (now_pivot < goal.size())
    {
        while (cards1[x_pivot] == goal[now_pivot])
        {
            now_pivot++;
            x_pivot++;
        }
        while (cards2[y_pivot] == goal[now_pivot])
        {
            now_pivot++;
            y_pivot++;
        }
        if (cards1[x_pivot] != goal[now_pivot] && cards2[y_pivot] != goal[now_pivot])
        {
            now_pivot++;
        }
    }
    if (y_pivot + x_pivot == goal.size())
    {
        return "Yes";
    }

    return "No";
}