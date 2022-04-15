#include <iostream>
#include <queue>

using namespace std;

int lader;
int snake;
bool used[101];
int snakelader[101];

void bfs()
{
    queue<pair<int,int> > q;
    q.push(make_pair(1,0));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == 100)
        {
            cout << y;
            break;
        }
        for (int i = 1; i < 7; i++)
        {
            if (!used[x+i] && x+i < 101)
            {
                if (snakelader[x+i])
                {
                    if (!used[snakelader[x+i]])
                    {
                        q.push(make_pair(snakelader[x+i],y+1));
                        used[snakelader[x+i]] = 1;
                    }
                }
                else
                {
                    used[x+i] = 1;
                    q.push(make_pair(x+i,y+1));
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> lader >> snake;
    for (int i = 0; i< lader + snake; i++)
    {
        int a, b;
        cin >> a >> b;
        snakelader[a] = b;
    }
    bfs();
    return 0;
}