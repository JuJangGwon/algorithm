#include <iostream>
#include <queue>

using namespace std;

int a, b;
int result, num;
bool used[1000010];

void bfs()
{
    queue<pair<int,int> > q;
    q.push(make_pair(a,0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        used[x] = true;
        if (result && x == b && result == y)
        {
            num++;
        }
        if (!result && x == b)
        {
            result = y;
            num++;
        }
            if (x - 1 >= 0 && !used[x - 1])
            {
                q.push(make_pair(x-1,y+1));
            }
            if (!used[x+1] && x + 1 <= 100000)
            {
                q.push(make_pair(x+1,y+1));
            }
            if (!used[x*2] && x * 2 <= 100000)
            {
                q.push(make_pair(x*2,y+1));
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    bfs();

    cout << result << "\n" << num;
    return 0;
}