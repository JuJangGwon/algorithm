#include <string>
#include <vector>
#include <math.h>

using namespace std;

int parent[101];

int findpa(int a)                               // 부모찾기
{
    if (parent[a] == a) return a;
    return parent[a] = findpa(parent[a]);
}
void unionpa(int a, int b)                      // 결합
{
    a = findpa(a);
    b = findpa(b);
    if (a < b)
        parent[b] = a;
    else if (a > b)
        parent[a] = b;
}

int solution(int n, vector<vector<int> > wires) {
    int answer = 101;
    int temp = 0;                               // 끊을 송전탑 
    
    for (int i = 0; i < wires.size(); i++)
    {
        for (int j = 1; j <= n; j++)            // 노드 초기화 
        {
            parent[j] = j;
        }
        for (int j = 0; j < wires.size(); j++) 
        {
            if (j == temp)                      // 끊을 송전탑은 union 제외하기 
                continue;
            unionpa(wires[j][0],wires[j][1]);
        }
        int t = 0;                              // 갯수 세기용 임시 변수
        for (int j = 1; j <= n; j++)
        {
            parent[j] = findpa(j);
        }
        for (int j = 1; j <= n; j++)
        {
            if (parent[j] == 1)
                t++;
        }
        answer = min(answer, abs(n - t * 2));
        temp++;
    }
    return answer;
}