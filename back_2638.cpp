#include <iostream>
#include <queue>

using namespace std;

int a, b, c = 1;
int map[101][101];
int tmap[101][101];
bool bmap[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void find()
{
    queue<pair<int, int> > q;
    q.push(make_pair(1,1));
    bmap[1][1] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (yy >= 1 && xx >=1 && xx <= b && yy <= a && !bmap[yy][xx])
            {
                if (map[yy][xx] == 1)
                {
                    c++;
                    tmap[yy][xx]--;
                }
                else
                {
                    bmap[yy][xx] = true;
                    q.push(make_pair(xx,yy));
                }
            }
        }
    }
}
void clear()
{
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1 ; j <= b ; j++)
        {
            tmap[i][j] = 0;
            bmap[i][j] = 0;
        }
    }
}
void mi()
{
    for (int i = 1; i <= a; i++)
    {
        for (int j =1 ; j<= b; j++)
        {
            if (tmap[i][j] <= -2)
            {
                map[i][j] = 0;
            }
        }
    }
}
int main()
{
    int d = 0;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> map[i][j];
        }
    }
    while(c != 0)
    {
        c = 0;
        clear();
        find();
        if (c == 0)
        {
            cout << d;
            break;
        }
        mi();
        d++;
    }
    // for (int i = 1; i <= a; i++)
    // {
    //     for (int j =1 ; j<= b; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}