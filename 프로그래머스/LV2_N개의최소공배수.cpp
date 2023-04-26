#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    int Last;
    int Now;
    bool check;

    sort(arr.begin(), arr.end());
    Last = arr.back();
    Now = Last;

    while (1)
    {
        check = 1;
        for (auto &i : arr)
            if (Now % i != 0)
            {
                check = 0;
                break;
            }
        if (check)
            return Now;
        Now += Last;
    }
}