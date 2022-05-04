    #include <iostream>
    #include <queue>

    using namespace std;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int a, b;
    int map[1001][1001];
    int bmap[1001][1001][2];

    int bfs()
    {
        queue<pair<pair<int,int>,pair<int,int> > >q;
        q.push(make_pair(make_pair(1,1),make_pair(1,0)));
        bmap[1][1][0] = true;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second.first;
            int breakblock = q.front().second.second;
            if (x == b && y == a)
            {
                return time;
            }
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 1 && xx <= b && yy >= 1 && yy <= a && !bmap[yy][xx][breakblock])
                {
                    if (map[yy][xx] == 0 )
                    {
                        bmap[yy][xx][breakblock] = true;
                        q.push(make_pair(make_pair(xx,yy),make_pair(time+1,breakblock)));
                    }
                    else if (map[yy][xx] == 1 && breakblock == 0)
                    {
                        bmap[yy][xx][1] = true;
                        q.push(make_pair(make_pair(xx,yy),make_pair(time+1,breakblock+1)));

                    } 
                }
            }
        }
        return -1;
    }

    int main()
    {
        cin >> a >> b;
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                scanf("%1d",&map[i][j]);
            }
        }
        int o = bfs();
        cout << o;
    }