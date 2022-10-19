#include <string>
#include <vector>
#include <math.h>

using namespace std;
bool prime[1000001];
int solution(int n) {
    
    int answer = 0;
    for (int i =2; i<= abs(n); i++)
    {
        if (prime[i] == true)
            continue ;
        for (int j = 2; j * i <= n; j++)
        {
            prime[j*i] = true;
        }
    }
    for (int i = 2; i <=n ;i++)
    {
        if (prime[i] == false)
            answer++;
    }
    return answer;
}