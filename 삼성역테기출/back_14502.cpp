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
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void clear()            // 배열 초기화 해주는 함수
{
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <=b; j++)
        {
            tempmap[i][j] = map[i][j];
            used[i][j] = false;
        }
    }
}
int check()             // 바이러스 없는땅 갯수 return 
{
    int sum = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j<= b; j++)
        {
            if (tempmap[i][j] == 0)
            {
                sum++;
            }
        }
    }
    return sum;
}

void bfs()                          // 바이러스 퍼지게하는 함수
{
    clear();

    queue<pair<int,int> >q;
    for(int i = 0; i < virus.size(); i++)           // 처음에 좌표입력 받을 때 바이러스 위치 기억해둔거 q에 넣기                
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


void dfs(int now,int x, int y)              // dfs로 벽 조합 만들기 
{
    if (now == 3)           // 벽이 3개 만들어지면 바이러스 퍼트려서 안전한곳 몇개인지 체크
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
            if (map[i][j] == 2)                 // 바이러스 위치 벡터에 입력하기 
                virus.push_back(make_pair(j,i));    
        }
    }
    dfs(0,1,1);
    cout << maxx;
    return 0;
}