#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <memory.h>

using namespace std;

int n, m;
bool bb[10001];

void bfs()
{
    string now_st;
    queue<pair<int, string> >q;
    q.push(make_pair(n,now_st));
    while (!q.empty())
    {
        int now = q.front().first;
        now_st = q.front().second;
        q.pop();
        if (now == m)
        {
            cout << now_st << "\n";
            return ;
        }
        int ovo;
        // D
        if (now * 2 > 9999)
            ovo = (now * 2) % 10000;
        else
            ovo = now * 2;
        if (!bb[ovo])
        {
           bb[ovo] = true;
           q.push(make_pair(ovo,now_st + 'D'));
        }
        // S
        if (now == 0)
            ovo = 9999;
        else
            ovo = now - 1;
        if (!bb[ovo])
        {
            bb[ovo] = true;
            q.push(make_pair(ovo,now_st + 'S'));
        }
        // L
        ovo = (now % 1000) * 10 + now / 1000;
        if (!bb[ovo])
        {
            bb[ovo] = true;
            q.push(make_pair(ovo,now_st + 'L'));
        }
        // R
        ovo = (now % 10) * 1000 + (now / 10);
        if (!bb[ovo])
        {
            bb[ovo] = true;
            q.push(make_pair(ovo, now_st+'R'));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> n >> m;
        bfs();
        memset(bb,false,10000);
    }
    return 0;
}