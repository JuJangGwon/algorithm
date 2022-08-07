#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];                            // 부모

bool cmp(vector<int> a, vector<int> b)      // 정렬할 때 조건 넣기용 함수
{
    return a[2] < b[2];
}

    int findparent(int a)                   // 부모 찾기 함수
    {
        if (parent[a] == a) return parent[a];
        return parent[a] = findparent(parent[a]);
    }

    void unionparent(int a, int b)          // 결합하는 함수
    {
        a = findparent(a);
        b = findparent(b);
        if (b > a)
            parent[b] = a;
        else if (b < a)
            parent[a] = b;
    }
    bool sameparent(int a, int b)           // 싸이클 유무가있는지 확인하는 함수
    {
        if (findparent(a) == findparent(b))
            return true;
        return false;
    }

int solution(int n, vector<vector<int> > costs)     
{
    int answer = 0;
    for (int i = 0; i < n; i++)                 // 초기화
        parent[i] = i;
    sort(costs.begin(),costs.end(),cmp);        // 비용이 낮은순으로 정렬하기
    for (int i = 0; i < costs.size(); i++)
    {
        if (!sameparent(costs[i][0],costs[i][1]))   // 싸이클이 없으면 연결해주기
        {
            unionparent(costs[i][0],costs[i][1]);
            answer+= costs[i][2];
        }
    }
    return answer;
}