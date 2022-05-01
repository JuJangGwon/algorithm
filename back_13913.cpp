#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int a,b;
bool used[100001];
int track[100001];

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(a, 1));
    used[a] = true;
    while (!q.empty())
    {
        int c = q.front().first; // 값 
        int d = q.front().second; // 싸이클

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
            track[c-1] = c;
        }
        if (c + 1 <= b && !used[c+1])
        {
            q.push(make_pair(c+1, d+1));
            used[c+1] = true;
            track[c+1] = c;
        }
        if (c* 2 <= 100000 && !used[c*2])
        {
            q.push(make_pair(c*2, d + 1));
            used[c*2] = true;
            track[c*2] = c;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;

    bfs();
    cout << "\n";
    stack<int> s;
    s.push(b);
    while (b != a)
    {
        s.push(track[b]);
        b = track[b];
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;

}