#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[126][126];
int dist[126][126];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int test = 1;

void clear(int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            map[i][j] = 0;
            dist[i][j] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        int a;
        cin >> a;
        if (a == 0)
            return 0;
        for (int i = 0; i< a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                dist[i][j] = 2111111111;
            }
        }
        priority_queue<pair<int,pair<int, int> > ,vector<pair<int, pair <int ,int> > >,greater<pair<int,pair <int, int> > > > pq;
        pq.push(make_pair(map[0][0],make_pair(0,0)));
        dist[0][0] = map[0][0];
        while (!pq.empty())
        {
            int now_x = pq.top().second.first;
            int now_y = pq.top().second.second;
            int val = pq.top().first;
            pq.pop();
            if (dist[now_y][now_x] < val)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int xx = now_x+dx[i];
                int yy = now_y+dy[i];
                if (yy >= 0 && yy < a && xx >= 0 && xx < a)
                {
                    int valval = val + map[yy][xx];
                    if (dist[yy][xx] > valval)
                    {
                        dist[yy][xx] = valval;
                        pq.push(make_pair(dist[yy][xx],make_pair(xx,yy)));
                    }
                }
            }
        }
        cout << "Problem "<< test++ << ": " << dist[a-1][a-1] << "\n";
        clear(a);

    }
    return 0;
}