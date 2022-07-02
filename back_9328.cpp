#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

char getkey[27];
char map[101][101];
vector<pair<int,int> > door;
vector<pair<int,int> > alpa[27];

int visited[101][101];
int x, y, t, result;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

string str;

void bfs(int xxx, int yyy)
{
    queue<pair<int,int> > q;
    q.push(make_pair(xxx,yyy));
    while(!q.empty())
    {
        int x1 = q.front().first;
        int y1= q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int xx = x1+dx[i];
            int yy = y1+dy[i];
            if (xx >= 1 && yy >= 1 && xx <= x && yy <= y && !visited[yy][xx] && map[yy][xx] != '*')
            {
                if (map[yy][xx] >= 'a' && map[yy][xx] <= 'z')                // 키 줍기
                {
                    getkey[map[yy][xx]-'a']++;
                    visited[yy][xx]++;
                    q.push(make_pair(xx,yy));
                    for (int i = 0; i < alpa[map[yy][xx]-'a'].size(); i++)
                    {
                        q.push(make_pair(alpa[map[yy][xx]-'a'][i].first,alpa[map[yy][xx]-'a'][i].second));
                    }
                }
                else if (map[yy][xx] >= 'A' && map[yy][xx] <= 'Z')              // 방문 도착
                {
                    if (getkey[map[yy][xx]-'A'])    // 키있을때 
                    {
                        q.push(make_pair(xx,yy));
                        visited[yy][xx]++;
                    }
                    else            // 키없을 때
                    {
                        alpa[getkey[map[yy][xx]-'A']].push_back(make_pair(xx,yy));
                    }
                }
                else if (map[yy][xx] == '$')
                {
                    result++;
                    visited[yy][xx]++;
                }
                else                                                            // 그냥 땅일때
                {
                    visited[yy][xx]++;
                    q.push(make_pair(xx,yy));
                }
            }
        }
        
    }
}

void find_door()                     // 입구 찾는 함수
{
    for (int i = 1; i <= y; i++)
    {
        if(map[i][1] != '*')
            door.push_back(make_pair(1,i));
        if(map[i][x] != '*')
            door.push_back(make_pair(x,i));
    }
    for (int i = 2; i <= x-1; i++)
    {
        if(map[1][i] != '*')
            door.push_back(make_pair(i,1));
        if(map[y][i] != '*')
            door.push_back(make_pair(i,y));
    }
}
void init()
{
    cin >> y >> x;   
    for (int i = 1; i<= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            scanf("%1c",&map[i][j]);
        }
    }
    cin >> str;
    if (str[0] != '0')
    {
        for (int i =0; i < str.size(); i++)
        {
            getkey[str[i]-'a']++;
        }
    }
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
  
    find_door();                // 입구 찾기
    ////////////////////////////
    }
}