#include <iostream>
#include <queue>

using namespace std;

int a, b;

void bfs()
{
    queue<pair<long long ,long long> > q;
    q.push(make_pair(a,1));
    while(!q.empty())
    {
        long long x = q.front().first;
        long long y = q.front().second;
        if (x == b)
        {
            cout << y;
            break;
        }
        q.pop();
        if (x*10 + 1 <= b)
        {
            q.push(make_pair(x*10 + 1, y+1));
        }
        if (x * 2 <= b)
        {
            q.push(make_pair(x*2, y+1));
        }
    }
    if (q.empty())
        cout << "-1";
}

int main()
{
    cin >> a >> b;
    bfs();
    return 0;
}