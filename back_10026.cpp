    #include <iostream>
    #include <queue>
    #include <vector>
    #include <cstring>

    using namespace std;

    int dx[4] = { 0,0, 1, -1};
    int dy[4] = { 1,-1,0,0};
    bool used[101][101];
    char map[101][101];

    bool juckrock = false;          // 적록색약 사람인지 아닌지 체크하는 변수 
    int n, area, sarea;

    void clear()                    // 방문 배열 초기화 함수 
    {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            used[i][j] = false;
        }
    }
    }
    void check_bfs(int x, int y,char c)             // 주변에 같은 색 찾는 bfs()함수                                                                  
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
                    if (juckrock == false && map[yy][xx] == c)              // 적록색약 아닌 사람시점 
                    {
                        used[yy][xx] = true;
                        q.push(make_pair(xx,yy));
                    }
                    else if (juckrock == true)                              // 적록색약인 사람 시점 
                    {
                        if (c == 'B' && map[yy][xx] == c)
                        {
                            used[yy][xx] = true;
                            q.push(make_pair(xx,yy));
                        }
                        else if (c == 'R' || c == 'G')                  // R = G
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
        for (int i = 1; i <= n; i++)        // 입력 받기
        {
            for (int j = 1; j <= n; j++)
            {
                char in;
                cin >> in;
                map[i][j] = in;
            }
        }
        for (int i = 1; i <= n; i++)        // 적록색약 아닌사람 시점으로 구역 갯수 확인 하기 
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
        cout << area << " ";        // 적록색약 아닌사람 시점 구역 갯수 출력
        juckrock = true;        // 적록색약 시점 on 
        clear();        // 방문 배열 초기화
        for (int i = 1; i <= n; i++)            // 적록색약 인사람 시점 구역 갯수 확인
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