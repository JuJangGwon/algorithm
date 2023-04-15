#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    bool check = false;
    vector<int> temp;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                temp.push_back(nums[i] + nums[j] + nums[k]);
            }
        }
    }
    sort(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
    {
        check = false;
        for (int j = 2; j < temp[i]; j++)
        {
            if (temp[i] % j == 0)
            {
                check = false;
                break;
            }
            check = true;
        }
        check == true ? answer++ : answer;
    }
    return answer;
}