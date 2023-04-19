#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0, start = 1;

    while (start <= n)
    {
        int tmp = 0;

        for (int i = start; tmp <= n; i++)
        {
            if (tmp == n)
                answer++;
            tmp += i;
        }
        start++;
    }
    return answer;
}