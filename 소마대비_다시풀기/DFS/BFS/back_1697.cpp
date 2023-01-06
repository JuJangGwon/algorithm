#include <iostream>
#include <queue>

using namespace std;

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
        if (x * 2 <= 100000)
        {
            q.push(make_pair(time+1, x*2));
        }
        if (x + 1 <= 100000)
        {
            q.push(make_pair(time+1, x+1));
        }
        if (x - 1 >= 0)
        {
            q.push(make_pair(time+1, x-1));
        }
    }
    return 0;
}