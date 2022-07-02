#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int map[102][102];
int x,y,result;
int player_x = 0;
bool shocks[10001];

class Shark
{
    public:
    int x;
    int y;
    int speed;
    int dir;            // 1 위 // 2 아래 // 3 오른쪽 // 4 왼쪽 
    int size;
    Shark(int x, int y, int speed, int dir, int size)
    {
        this->x = x;
        this->y = y;
        this->speed = speed;
        this->dir = dir;
        this->size = size;
    }
};
vector<Shark> v;

int eat_shark(int a,int b)
{
    if (v[a-1].size > v[b-1].size)
    {   
        //cout << v[b-1].size;
        shocks[b-1] = true;
        return a;
    }
    else
    {
        //cout << v[a-1].size;
        shocks[a-1] = true;
        return b;
    }
}
void clear()
{
    for (int i = 1; i <= y; i++)
    {
        for (int j =1; j<= x; j++)
        {
            map[i][j] = 0;
        }
    }
}
void move_shark()
{
    clear();
    //memset(map,0,sizeof(map));
    for (int i = 0; i < v.size(); i++)
    {
        int shark_x = v[i].x;
        int shark_y = v[i].y;
        int shark_dir = v[i].dir;
        int shark_speed = v[i].speed;
        int shark_power = v[i].size;
        while (shark_speed != 0)
        {
            if (shark_dir == 1)  // up
            {
                shark_y--;
                if (shark_y == 0)
                {
                    shark_y = 2;
                    shark_dir = 2;
                }
            }
            else if (shark_dir == 2)  // down
            {
                shark_y++;
                if (shark_y == y+1)
                {
                    shark_y = y-1;
                    shark_dir = 1;
                }
            }
            else if (shark_dir == 3)   // right 
            {
                if (shark_x == x)
                {
                    shark_x--;
                    shark_dir = 4;
                }
                else
                    shark_x++;
            }
            else if (shark_dir == 4)    // left
            {
                if (shark_x == 1)
                {
                    shark_x++;
                    shark_dir = 3;
                }
                else
                    shark_x--;
            }
            shark_speed--;
        }
        if (!map[shark_y][shark_x]) // 현재 위치에 상어가 없으면
        {              
            v[i].y = shark_y;
            v[i].x = shark_x;
            v[i].dir = shark_dir;
            map[shark_y][shark_x] = i + 1;
        }
        else         // 현재 위치에 상어가 있으면
        {
            int c = eat_shark(map[shark_y][shark_x], i + 1);
            v[c-1].x = shark_x;
            v[c-1].y = shark_y;
            v[c-1].dir = shark_dir;
            map[shark_y][shark_x] = c;
        }
    }
    vector<Shark> sh;

    for (int i = 0; i < v.size(); i++)
    {
        if(shocks[i])
        {
            shocks[i] = false;
        }
        else
        {
            sh.push_back(v[i]);
        }
    }
    v = sh;
}

void fish_shark()
{
    player_x++;
    int min = -1;
    int y = 101;
    for (int i = 0; i < v.size();i++)
    {
        if (v[i].x == player_x)
        {
            if (y > v[i].y)
            {
                min = i;
                y = v[i].y;
            }
        }
    }
    if (min != -1)               // 가까이있는 물고기 찾았으면 낚시
    {
      //  cout << "player_x : " << player_x << "  fish : " << v[min].size << endl;
        result += v[min].size;
        v.erase(v.begin() + min);
    }

}
void Simul()
{
    while (1)
    {
        if (player_x == x)
        {
            cout << result;
            return ;
        }
        // cout << endl;
        // for (int i = 1; i <= y ;i++)
        // {
        //     for (int j = 1; j<= x; j++)
        //     {
        //         cout << v[map[i][j]-1].size << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "낚시\n";
        fish_shark();
        //cout << "움직이기\n";
        move_shark();

        // cout << endl;
        // for (int i = 1; i <= y ;i++)
        // {
        //     for (int j = 1; j<= x; j++)
        //     {
        //         cout << v[map[i][j]-1].size << " ";
        //     }
        //     cout << endl;
        // }
    }
}

int main()
{
    int shark_num;
   ios::sync_with_stdio(false);
   cin.tie(NULL);
    cin >> y >> x  >> shark_num;
    for (int i = 0; i < shark_num; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        Shark sh = Shark(b,a,c,d,e);
        v.push_back(sh);
        map[a][b] = v.size();
    }
    if (shark_num == 0)
    {
        cout << "0";
        return 0;
    }
    Simul();
    return 0;
}