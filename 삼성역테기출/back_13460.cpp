#include <iostream>
#include <queue>

using namespace std;

int a, b, mins = -1;
char map[12][12];
pair<int, int> b_pos;
pair<int, int> r_pos;
pair<int, int> arrive_pos;

// red 1, blue 2
int right_move(int x, int y,int xx, int yy, int ball)
{
    while (b > x + 1 && (map[y][x+1] == '.'))
    {
        if (y == arrive_pos.second && x == arrive_pos.first)
        {
            if (ball == 1)
                return -1;      // 끝
            else if (ball == 2)
                return -2;      // 게임 끝
        }
        if (x == xx && y == yy)
        {
            if (x == 2)
                return 2;
            x--;
            break;
        }
        x++;
    }
       if (x == 1)
    {
      //  cout << "()()()";
    }
    return x;
}
int left_move(int x, int y,int xx, int yy, int ball)
{
     while (x-1 >= 2 && (map[y][x-1] == '.' ))
    {
        if (y == arrive_pos.second && x == arrive_pos.first)
        {
            if (ball == 1)
                return -1;      // 끝
            else if (ball == 2)
                return -2;      // 게임 끝
        }
        if ((x == xx && y == yy))
        {
            if (x == b-1)
                return b-1;
            x++;
            break;
        }
        x--;
    }
    if (x == 1)
    {
       // cout << "()()()";
    }
    return x;
}
int up_move(int x, int y,int xx, int yy, int ball)
{
    while (a > y + 1 && (map[y+1][x] == '.'))
    {
        //cout << "*";
        if (y == arrive_pos.second && x == arrive_pos.first)
        {
            if (ball == 1)
                return -1;      // 끝
            else if (ball == 2)
                return -2;      // 게임 끝
        }
        if (x == xx && y == yy)
        {
            if (y == 2)
                return 2;
            y--;
            break;
        }
        y++;
    }
    return y;
}
int down_move(int x, int y,int xx, int yy, int ball)
{
    while (y-1 >= 2 && map[y-1][x] == '.')
    {
        if (y == arrive_pos.second && x == arrive_pos.first)
        {
            if (ball == 1)
                return -1;      // 끝
            else if (ball == 2)
                return -2;      // 게임 끝
        }
        if (x == xx && y == yy)
        {
            if (y == a -1)
                return a - 1;
            y++;
            break;
        }
        y--;
    }
    return y;
}
void bfs()
{
    queue< pair < pair < pair <int, int>, pair <int, int > > , int> >  q; 
    q.push(make_pair(make_pair(r_pos,b_pos),0));
    while(!q.empty())
    {
        int r_x =  q.front().first.first.first;
        int r_y = q.front().first.first.second;
        int b_x = q.front().first.second.first;
        int b_y = q.front().first.second.second;
        int time = q.front().second;
        q.pop();
        cout << r_x << ", " << r_y << " | ";
        // 오른쪽
        if (time <= 3)
        {
            if (r_x >= b_x)
            {
                int x = right_move(r_x,r_y,b_x,b_y,1);
                int x2 = right_move(b_x,b_y,x,r_y,2);
                if (x != -2 && x2 != -2)
                {
                    if (x == -1 || x2 == -1)
                    {
                        mins = time;
                        return ;
                    }
                    else
                    {
                        q.push(make_pair(make_pair(make_pair(x,r_y),make_pair(x2,b_y)),time+1));
                    }
                }
            } 
            else
            {
                int x = right_move(b_x,b_y,r_x,r_y,2);
                int x2 = right_move(r_x,r_y,x,b_y,1);
                if (x != -2 && x2 != -2)
                {
                    if (x == -1 || x2 == -1)
                    {
                        mins = time;
                        return ;
                    }
                    else
                    {
                        q.push(make_pair(make_pair(make_pair(x2,r_y),make_pair(x,b_y)),time+1));
                    }
                }
            }
        // left
        if (r_x <= b_x)
        {
            int x = left_move(r_x,r_y,b_x,b_y,1);
            int x2 = left_move(b_x,b_y,x,r_y,2);
            if (x != -2 && x2 != -2)
            {
                if (x == -1 || x2 == -1)
                {
                    //cout << x << x2;
                    mins = time;
                    return ;
                }
                else
                    q.push(make_pair(make_pair(make_pair(x,r_y),make_pair(x2,b_y)),time+1));
            }
        }
        else
         {
            int x = left_move(b_x,b_y,r_x,r_y,2);
            int x2 = left_move(r_x,r_y,x,b_y,1);
            if (x != -2 && x2 != -2)
            {
                if (x == -1 || x2 == -1)
                {
                    mins = time;
                    return ;
                }
                else
                    q.push(make_pair(make_pair(make_pair(x2,r_y),make_pair(x,b_y)),time+1));
            }
        }
        // up
        if (r_y >= b_y)
        {
            int y = up_move(r_x,r_y,b_x,b_y,1);
            int y2 = up_move(b_x,b_y,r_x,y,2);
            if (y != -2 && y2 != -2)
            {
                if (y == -1 || y2 == -1)
                {
                    mins = time;
                    return ;
                }
                else
                    q.push(make_pair(make_pair(make_pair(r_x,y),make_pair(b_x,y2)),time+1));
            }
        }
        else
         {
            int y = up_move(b_x,b_y,r_x,r_y,2);
            int y2 = up_move(r_x,r_y,b_x,y,1);
            if (y != -2 && y2 != -2)
            {
                if (y == -1 || y2 == -1)
                {
                    mins = time ;
                    return ;
                }
                else
                    q.push(make_pair(make_pair(make_pair(r_x,y2),make_pair(b_x,y)),time+1));
            }
        }
        // down
        if (r_y <= b_y)
        {
            int y = down_move(r_x,r_y,b_x,b_y,1);
            int y2 = down_move(b_x,b_y,r_x,y,2);
            if (y != -2 && y2 != -2)
            {
                if (y == -1 || y2 == -1)
                {
                    mins = time;
                    return ;
                }
                else
                    q.push(make_pair(make_pair(make_pair(r_x,y),make_pair(b_x,y2)),time+1));
            }
        }
        else
         {
             int y = down_move(b_x,b_y,r_x,r_y,2);
            int y2 = down_move(r_x,r_y,b_x,y,1);
            if (y != -2 && y2 != -2)
            {
                if (y == -1 || y2 == -1)
                {
                    mins = time;
                    return ;
                }
                else
                    q.push(make_pair(make_pair(make_pair(r_x,y2),make_pair(b_x,y)),time+1));
            }
        }
    }
    }
}
int main()
{
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j<= b; j++)
        {
            scanf("%1s",&map[i][j]);
            
            if (map[i][j] == 'R')
            {
                r_pos = make_pair(j,i);
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B')
            {
                b_pos = make_pair(j,i);
                map[i][j] = '.';
            }
            if (map[i][j] == 'O')
            {
                arrive_pos = (make_pair(j,i));
                map[i][j] = '.';
            }
        }
    }
    // for (int i =1; i <= a; i++)
    // {
    //     for (int j =1 ; j<=b ; j++)
    //     {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
     bfs();
     if(mins == 0)
        mins = 1;
     cout << mins;
    return 0;
}