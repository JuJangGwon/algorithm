#include <string>
#include <vector>

using namespace std;

int parent[201];
bool pa[201];

int findparent(int a)
{
    if (parent[a] == a) return a;
    return parent[a] = findparent(parent[a]);
}

void unionparent(int a, int b)
{
    a = findparent(a);
    b = findparent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int solution(int n, vector<vector<int> > computers) 
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (computers[i][j] == 1)
            {
                unionparent(i,j);
            }
        }
    }
    for(int i = 0; i < n; i++)
        parent[i] = findparent(i);
    for (int i = 0; i < n; i++)
    {
        if (!pa[parent[i]])
        {
            pa[parent[i]] = true;
            answer++;
        }
    }
    return answer;
}