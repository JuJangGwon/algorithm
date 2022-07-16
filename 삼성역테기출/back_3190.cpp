#include <iostream>
#include <deque>
#include <queue>

using namespace std;

queue<pair <int, char> > xc;        // 이동명령 넣는 pair
deque<pair<int, int> >dq;           // 뱀 몸 위치 담는 덱                                  

int map[102][102]; // 1 사과 // 2 뱀 
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dir = 1; // 1 right 2 down 3 left 4 up
int m;
int sec = 1;

int main()
{
    cin >> m;
    int n;
    cin >> n;
    for (int i = 1; i<=n ;i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;      // 맵에 사과 그리기
    }
    int nn;
    cin >> nn;
    for (int i = 1; i<= nn;i++)
    {
        int a;
        char b;
        cin >> a >> b; 
        xc.push(make_pair(a,b));        // 명령 넣기 
    }
    dq.push_back(make_pair(1,1));
    while (1)
    {
        int player_x = dq.front().first;
        int player_y = dq.front().second;
        //cout << player_x << ", " << player_y << " size : " << dq.size() << " sec : " << sec << endl;
        // 커브
        // 이동
        if (dir == 1)
        {
            dq.push_front(make_pair(player_x+1,player_y));
        }
        else if (dir == 2)
        {
            dq.push_front(make_pair(player_x,player_y-1));
        }
        else if (dir == 3)
        {
            dq.push_front(make_pair(player_x-1,player_y));
        }
        else if (dir == 4)
        {
            dq.push_front(make_pair(player_x,player_y+1));
        }
        sec++;      // 한번 진행때마다 1초씩 늘려주기
        // 끝나는지 안끝나는지 체크
        if (map[dq.front().second][dq.front().first] == 2)
        {
            break ;
        }
        if (dq.front().second == 0 || dq.front().second == m+1 || dq.front().first == 0 || dq.front().first == m+1)
        {
            break; 
        }
        // 꼬리지울지 안지울지 체크
        if (map[dq.front().second][dq.front().first] == 0)      // 0일때 
        {
            map[dq.back().second][dq.back().first] = 0;
            dq.pop_back();
        }
        map[dq.front().second][dq.front().first] = 2;   
        if (sec-1 == xc.front().first)
        {
            if (xc.front().second == 'D') // 왼
            {
                dir--;
                if (dir == 0)
                    dir = 4;
            } 
            else if (xc.front().second == 'L') // 오
            {
                dir++;
                if (dir == 5)
                {
                    dir = 1;
                }
            }
            xc.pop();
        }     
    }
    cout << sec-1;
}