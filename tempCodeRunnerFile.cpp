    #include <iostream>
    #include <queue>

    using namespace std;

    bool finish;
    int f,s,g,u,d;
    bool bnum[1000001];

    void bfs()
    {
        queue <pair<int, int> > q;
        q.push(make_pair(s,0));
        bnum[s] = true;
        while (!q.empty())
        {
            int time = q.front().second;
            int num = q.front().first;
            q.pop();
            if (num == g)
            {
                finish = true;
                cout << time;
                return ;
            }
            if (!bnum[num+u] && num + u <= f)
            {
                bnum[num+u] = true;
                q.push(make_pair(num+u,time+1));
            }
            if (!bnum[num-d] && num - d > 0)
            {
                bnum[num-d] = true;
                q.push(make_pair(num-d,time+1)); 
            }
        }
        if (finish == false)
        {
            cout << "use the stairs";
        }
    }

    int main()
    {
        cin >> f >> s >> g >> u >> d;
        bfs();
        return 0;
    }