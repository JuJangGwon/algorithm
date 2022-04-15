#include <iostream>
#include <queue>

using namespace std;

int a,b;
bool used[100001];

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(a, 1));
    used[a] = true;
    while (!q.empty())
    {
        int c = q.front().first;
        int d = q.front().second;

        if (c == b)
        {
            cout << d-1;
            break;
        }
        q.pop();
        if (c - 1 >= 0 && !used[c-1])
        {
            q.push(make_pair(c-1, d + 1));
            used[c-1] = true;
        }
        if (c + 1 <= b && !used[c+1])
        {
            q.push(make_pair(c+1, d+1));
            used[c+1] = true;
        }
        if (c* 2 <= 100000 && !used[c*2])
        {
            q.push(make_pair(c*2, d + 1));
            used[c*2] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;

    bfs();
    return 0;

}