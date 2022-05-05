#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b;
int sum;
bool used[100001];

void bfs()
{
    priority_queue<pair<int, int>, vector<pair<int,int> > ,greater<pair<int,int> > >q;
    q.push(make_pair(0,a));
    used[a] = true;
    while (!q.empty())
    {
        int x = q.top().second;
        int y = q.top().first;
        q.pop();
        if (x == b)
        {
            cout << y;
            return ;
        }
        if (x-1>= 0 && !used[x-1])
        {
            used[x-1] = true;
            q.push(make_pair(y+ 1,x-1));
        }
        if (x+1 <= 100000 && !used[x+1])
        {
            used[x+1] = true;
            q.push(make_pair(y+1,x+1));
        }
        if (x*2 <= 100000 && !used[x*2])
        {
            used[x*2] = true;
            q.push(make_pair(y,x*2));
        }
    }
}

int main()
{
    cin >> a >> b;
    bfs();
    return 0;
}