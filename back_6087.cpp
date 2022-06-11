#include <iostream>
#include <queue>
#include <vector>
#define INF 2111111111

using namespace std;

vector<pair<int,int> > Cv;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char map[101][101];
int windowmap[101][101];

int a, b;

void clear()
{
    for (int i = 1; i <= b; i++)
    {
        for (int j =1; j<= a;j++)
        {
            windowmap[i][j] = INF;
        }
    }
}
void djikstra()
{
    priority_queue<pair<pair<int,int>,pair<int,int> >,vector<pair<pair<int,int>, pair<int,int> > >,greater<pair<pair<int,int>,pair<int,int> > > >pq; // 꺽은횟수 / 좌표 
    pq.push(make_pair(make_pair(0,0),Cv[1]));
    windowmap[Cv[1].second][Cv[1].first] = 0;
    while(!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int curv = pq.top().first.first;
        int piror_dir = pq.top().first.second;
        pq.pop();
        if (windowmap[y][x] < curv)
            continue ;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && yy >= 1 && xx <= a && yy <= b && map[yy][xx] != '*')
            {
                int next = curv;
                if (piror_dir != i + 1 && piror_dir != 0)
                {
                    next++;
                }
                if (windowmap[yy][xx] >= next)   // >= !! 
                {
                    windowmap[yy][xx] = next;
                    pq.push(make_pair(make_pair(next,i+1),make_pair(xx,yy)));
                }
            }
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i<= b; i++)
    {
        for (int j = 1; j <=a; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'C')
                Cv.push_back(make_pair(j,i));
        }
    }
    clear();
    djikstra();
    cout << windowmap[Cv[0].second][Cv[0].first] << "\n";

    // for (int i = 1; i<= b; i++)
    // {
    //     for (int j = 1; j <=a; j++)
    //     {
    //         if (windowmap[i][j] == INF)
    //             cout << "F ";
    //         else
    //         cout << windowmap[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}