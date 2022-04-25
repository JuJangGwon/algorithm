#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int day = 0;
bool finish = true;
int a, b, c;
int map[101][101];
bool used[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void clear()
{
    for (int i = 1; i<= a; i++)
    {
        for (int j =1; j<= a;j++)
        {
            used[i][j] = 0;
        }
    }
}

void clear2()
{
    for (int i = 1; i<= a; i++)
    {
        for (int j =1; j<= a;j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int x, int y)
{
    int sum = map[y][x];
    used[y][x] = true;
    vector<pair<int,int> >v;
    queue<pair<int, int> >q;
    q.push(make_pair(x, y));
    v.push_back(make_pair(x,y));
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            if (xxx >= 1 && yyy >= 1 && xxx <= a && yyy <= a && !used[yyy][xxx])
            {
                if (abs(map[yyy][xxx] - map[yy][xx]) >= b && abs(map[yyy][xxx] - map[yy][xx]) <= c)
                { 
                    sum+=map[yyy][xxx];
                    used[yyy][xxx] = true;
                    q.push(make_pair(xxx,yyy));
                    v.push_back(make_pair(xxx,yyy));
                }
            }
        }
    }
    if (v.size() >= 2)
    {
    finish = true;

    for (int i = 0; i < v.size();i++)
    {
        map[v[i].second][v[i].first] = sum / v.size();
    }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    for (int i = 1; i <= a ;i++)
    {
        for (int j = 1; j<=a; j++)
        {
            cin >> map[i][j];
        }
    }
    while (finish == true)
    {
        finish = false;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j<= a; j++)
            {
                if(j!= a && !used[i][j])
                {
                    if (abs(map[i][j] - map[i][j+1]) >= b && abs(map[i][j] - map[i][j+1]) <= c)
                    {
                        bfs(j,i);
                    }
                }
                if(i!=a && !used[i][j])
                {
                    if (abs(map[i][j] - map[i+1][j]) >= b && abs(map[i][j] - map[i+1][j]) <= c)
                     {
                        bfs(j,i);
                     }
                }
            }
        }
       // cout << endl;

       //clear2();
        clear();
        if (finish == true) day++;
    }
    cout << day;
    return 0;
}