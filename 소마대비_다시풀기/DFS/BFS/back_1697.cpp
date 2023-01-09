#include <iostream>
#include <queue>

using namespace std;
bool used[100001];

int main()
{
    queue<pair<int,int> > q;
    int n, m;
    cin >> n >> m;
    q.push(make_pair(0,n));
    while(!q.empty())
    {
        int x = q.front().second;
        int time = q.front().first;
        if (x == m)
        {
            cout << time;
            return 0;
        }
        q.pop();
        if (x * 2 <= 100000 && !used[x*2])
        {
            q.push(make_pair(time+1, x*2));
            used[x*2] = true;
        }
        if (x + 1 <= 100000&& !used[x+1])
        {
            q.push(make_pair(time+1, x+1));
            used[x+1] = true;
        }
        if (x - 1 >= 0&& !used[x-1])
        {
            q.push(make_pair(time+1, x-1));
            used[x-1] = true;
        }
    }
    return 0;
}