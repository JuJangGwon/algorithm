#include <iostream>
#include <queue>

using namespace std;

int map[17][17];
int n, ans;

// int dx[3] = {0,1,1};
// int dy[3] = {1,0,1}; 


// void bfs()
// {
//     queue<pair<int, int> >q;
//     q.push(make_pair(1,1));
//     while (!q.empty())
//     {
//         int x =q.front().first;
//         int y = q.front().second;
//         q.pop();
//         if (x == n && y == n)
//         {
//             ans++;
//         }
//         for (int i = 0; i < 3; i++)
//         {
//             int xx = x+dx[i];
//             int yy = y+dy[i];
//             if (xx >= 1 && yy >= 1 && xx <= n && yy <= n && !map[yy][xx])
//             {
//                 if (i == 2)
//                 {
//                     if (!map[y+1][x] && !map[y][x+1])
//                     {
//                         q.push(make_pair(xx,yy));
//                     }
//                 }
//                 else
//                     q.push(make_pair(xx,yy));
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n ; i++)
//     {
//         for (int j =1; j <=n; j++)
//         {
//             cin >> map[i][j];
//         }
//     }
//     bfs();
//     cout << ans;
// }
int main()
{
    cin >> n ;
    for (int i = 1; i <= n ; i++)    
     {
         for (int j =1; j <=n; j++)
         {
             cin >> map[i][j];
         }
     }
    return 0;
}