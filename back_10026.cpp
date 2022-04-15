    #include <iostream>
    #include <queue>
    #include <vector>
    #include <cstring>

    using namespace std;

    int dx[4] = { 0,0, 1, -1};
    int dy[4] = { 1,-1,0,0};
    bool used[101][101];
    char map[101][101];

    bool juckrock = false;
    int n, area, sarea;

    void clear()
    {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            used[i][j] = false;
        }
    }
    }
    void check_bfs(int x, int y,char c)
    {
        queue<pair<int, int> > q;
        q.push(make_pair(x,y));
        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 1 && xx <=n && yy >=1 && yy <= n && !used[yy][xx])
                {
                    if (juckrock == false && map[yy][xx] == c)
                    {
                        used[yy][xx] = true;
                        q.push(make_pair(xx,yy));
                    }
                    else if (juckrock == true)
                    {
                        if (c == 'B' && map[yy][xx] == c)
                        {
                            used[yy][xx] = true;
                            q.push(make_pair(xx,yy));
                        }
                        else if (c == 'R' || c == 'G')
                        {
                            if (map[yy][xx] == 'R' || map[yy][xx] == 'G')
                            {
                                used[yy][xx] = true;
                                q.push(make_pair(xx,yy));
                            }
                        }
                    }
                }
            }

        }
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
                char in;
                cin >> in;
                map[i][j] = in;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++)
            {
                if (used[i][j] == false)
                {
                    area++;
                    check_bfs(j,i,map[i][j]);
                }
            }
        }
        cout << area << " ";
        juckrock = true;
        clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++)
            {
                if (used[i][j] == false)
                {
                    sarea++;
                    check_bfs(j,i,map[i][j]);
                }
            }
        }
        cout << sarea;
        return 0;
    }