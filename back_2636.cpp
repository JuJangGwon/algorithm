#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a, b,cycle,num;
int map[101][101];
bool bmap[101][101];
int tmap[101][101];

vector<pair<int, int> >v;
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0};

void clear()
{
    for (int i = 1; i <= a; i++)
    {
        for (int j =1 ; j <= b; j++)
        {
            bmap[i][j] = 0;
            tmap[i][j] = 0;
        }
    }
}

void find()
{
    queue<pair <int ,int> >q;
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
            if (xx >= 1 && yy >= 1 && xx <= b && yy <= a && !bmap[yy][xx])
            {
                if (!map[yy][xx])
                {
                    bmap[yy][xx] = true;
                    q.push(make_pair(xx,yy));
                }
                else
                {
                    tmap[yy][xx]++;
                    if (tmap[yy][xx] == 1)
                        v.push_back(make_pair(xx,yy));
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
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> map[i][j];
        }
    }
    
    while(1)
    {
         int od = 0;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j<= b; j++)
            {
                if(map[i][j])
                    od++;
            }
        }
        if (od)
        {
            num = od;
        }
        find();
        if (!v.size())
        {
            cout << cycle << "\n" << num;
            break;
        }
        for (int i = 0; i < v.size();i++)
        {
            map[v[i].second][v[i].first] = 0;
        }
       
        clear();
        v.clear();
        cycle++;
    }
    return 0;
}