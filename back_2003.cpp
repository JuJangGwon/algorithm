#include <iostream>

// 2포인터 

int a, b;
int map[10001];
long long sum;
int coun;
using namespace std;

int main()
{
    cin >> a >> b;
    for (int i = 1; i<= a; i++)
    {
        cin >> map[i];
    }
    int start = 1;
    int end = 1;
    sum = map[1];
    while (start <= a && end <= a) 
    {
        if (sum < b)
        {
            end++;
            sum += map[end];
        }
        else if (sum == b)
        {
            end++;
            coun++;
            sum += map[end];
        }
        else if (sum > b)
        {
            sum = sum - map[start];
            start++;
        }
    }
    cout << coun;
    return 0;
}