    #include <iostream>
    using namespace std;

    char **board;

    int findDiff(int x, int y)
    {
        int BW_Cnt = 0;
        int WB_Cnt = 0;

        for (int i = x; i < x + 8; i++)
        {
            for (int j = y; j < y + 8; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    if (board[i][j] != 'B')
                        BW_Cnt++;
                    else
                        WB_Cnt++;
                }
                else
                {
                    if (board[i][j] != 'W')
                        BW_Cnt++;
                    else
                        WB_Cnt++;
                }
            }
        }

        if (BW_Cnt > WB_Cnt)
            return WB_Cnt;
        else
            return BW_Cnt;
    }

    int main()
    {
        cin.tie(NULL);
        ios::sync_with_stdio(false);

        int N, M;
        cin >> N >> M;

        board = new char *[N];
        for (int i = 0; i < N; i++)
            board[i] = new char[M];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> board[i][j];

        int min = -1;
        for (int i = 0; i + 7 < N; i++)
        {
            for (int j = 0; j + 7 < M; j++)
            {
                int cnt = findDiff(i, j);
                if (min == -1)
                    min = cnt;
                else if (min > cnt)
                    min = cnt;
            }
        }
        cout << min;

        return 0;
    }