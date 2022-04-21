#include <iostream>
#include <queue>

using namespace std;

int a, b;
int sum;
bool used[100001];

void bfs()
{
    queue<pair<int, int> >q;
    q.push(make_pair(a,0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == b)
        {
            cout << y;
            break;
        }
        if (!used[x-1] && x-1 >= 0)
        {
            used[x-1] = true;
            q.push(make_pair(x-1,y+1));
        }
        if (!used[x+1] && x+1 <= 100001)
        {
            used[x+1] = true;
            q.push(make_pair(x-1,y+1));
        }
    }
}

int main()
{
    cin >> a >> b;
    bfs();
}