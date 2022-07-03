#include <iostream>
#include <queue>
#include <vector>
#include "memory.h"

using namespace std;

int n;
int map[22][22];
bool bmap[22][22];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
pair<int,int> playerpos;                                 // 아기상어 위치
vector<pair<int,pair<int,int> > > find_fish_pos;           // 발견된 상어들 저장 벡터
int player_level = 2;           
int player_exp = 0;
int result = 0;

void clear()
{
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bmap[i][j] = 0;
        }
    }
}
// 주변 가까운 물고기 탐색
void find_fish(pair<int,int> pos)
{
    bool find = false;
    int minimum = 0;
    //memset(bmap,0,sizeof(bmap));
    clear();
    find_fish_pos.clear();
    priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int > > > > pq;
    pq.push(make_pair(0,make_pair(pos.first,pos.second)));
    while(!pq.empty())
    {
        int time = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (find == true && minimum <= time)
            continue ;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >=1 && yy >= 1 && xx <= n && yy <= n)
            {
                if (!bmap[yy][xx] && map[yy][xx] <= player_level)
                {
                    bmap[yy][xx] = true;
                    if (map[yy][xx] < player_level && map[yy][xx] > 0)
                    {
                        minimum = time + 1;
                        find = true;
                        find_fish_pos.push_back(make_pair(time+ 1,make_pair(xx,yy)));
                    }
                    else
                        pq.push(make_pair(time + 1, make_pair(xx,yy)));
                }
            }
        }
    }
    
}
void go()
{
    int x = find_fish_pos[0].second.first;
    int y = find_fish_pos[0].second.second;
    int t = find_fish_pos[0].first;
    for (int i = 1; i < find_fish_pos.size(); i++)       // 찾은 물고기가 많다면 가장 위 / 가장 왼쪽 물고기 찾기
    {
        if (t < find_fish_pos[i].first)
            break;
        if (y > find_fish_pos[i].second.second)
        {
            x = find_fish_pos[i].second.first;
            y = find_fish_pos[i].second.second;
        }
        else if (y == find_fish_pos[i].second.second)
        {
            if (x >= find_fish_pos[i].second.first)
            {
                x = find_fish_pos[i].second.first;
                y = find_fish_pos[i].second.second;
            }
        }
    }
    player_exp++;
    if (player_exp == player_level)                 // 레벨업 처리
    {
        player_exp = 0;
        player_level++;
    }
    // 이동
    map[y][x] = 0;
    playerpos.first = x;
    playerpos.second = y;
    result += t;

    // cout << endl;                            // 확인용
    // for (int i = 1; i <= 6; i++)
    // {
    //     for (int j = 1; j <= 6; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // map[y][x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                playerpos = make_pair(j,i);
                map[i][j] = 0;
            }   
        }
    }
    while (1)
    {
        find_fish(playerpos);
        if (!find_fish_pos.empty())                 // 주변에 물고기를 찾았다면?
        {
            go();                                   // 이동
        }  
        else                                          // 물고기 발견 못할시 끝 
            break;
    }
    cout << result << "\n";
    return 0;
}