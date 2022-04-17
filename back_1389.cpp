#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// vector<int> v[101];
// int used[101];

// int main()
// {
//     queue<int> q;
//     int a, b, min;
//     cin >> a >> b;

//     for (int i = 0; i < b; i++)
//     {
//         int c, d;
//         cin >> c >> d;
//         v[c].push_back(d);
//         v[d].push_back(c);
//     }
//     for (int i = 1; i <= 1; i++)
//     {
//         int sum = 0;
//         q.push(i);
//         used[i] = true;
//         while (!q.empty())
//         {
//             int a = q.front();
//             q.pop();
//             for (int j = 0; j < v[a].size(); j++)
//             {
//                 if (!used[v[a][j]])
//                 {
//                     q.push(v[a][j]);
//                     used[v[a][j]] = used[a] + 1;
//                 }
//             }
//         }
//         for (int i = 4; i <= 5; i++)
//         {
//             sum += used[i-1];
//         }
//         cout << sum;
//     }
// }


//
int map[101][101];
int used[101];

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int c, d;
        cin >> c >> d;
        map[c][d] = 1;
        map[d][c] = 1;
    }

    for (int k = 1; k <=a; k++)
    {
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= a; j++)
            {
                if (i != j && map[i][k] && map[k][j])
                {
                    if (map[i][j] == 0)
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                    else
                        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }
    }

    int min =999999;
    int p;
    for (int i = 1; i <= a; i++)
    {
        int sum = 0;
        for (int j = 1; j <= a; j++)
        {
            sum += map[i][j];
        }
        if (min > sum)
        {
            min = sum;
            p = i;
        }
    }
    cout << p;
}