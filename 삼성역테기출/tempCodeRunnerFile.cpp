#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a, b;
int map[9][9];
int tempmap[9][9];
int maxx = 0;
bool used[9][9];
vector<pair<int,int> >virus;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};

void clear()
{
    for (int i = 1;i <= a; i++)
    {
        for (int j =1;j <=b; j++)
        {
            tempmap[i][j] = map[i][j];
            used[i][j] = false;
        }
    }
}
int check()
{
    int sum = 0;
    for (int i = 1; i <= a; i++)
        for (int j =1 ; j<= b; j++)
            if (tempmap[i][j] == 0)
                sum++;
    return sum;
}

void bfs()
{
    clear();
    queue<pair<int,int> >q;
    for(int i = 0; i < virus.size(); i++)
    {
        q.push(make_pair(virus[i].first,virus[i].second));
        used[virus[i].second][virus[i].first] = true;
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i< 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >=1 && xx <= b && yy >= 1 && yy <= a && !used[yy][xx] && tempmap[yy][xx] == 0)
            {
                tempmap[yy][xx] = 2;
                used[yy][xx] = 1;
                q.push(make_pair(xx,yy));
            }
        }
    }
}

void dfs(int now,int x, int y)
{
    if (now == 3)
    {
        bfs();
        maxx = max(maxx,check());
        return ;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                dfs(now+1,j,i);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j =1 ;j <= b; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back(make_pair(j,i));    
        }
    }
    dfs(0,1,1);
    cout << maxx;
    return 0;
}