    #include <iostream>
    #include <queue>

    #define MAX 1000000 + 1
    using namespace std;

    bool finish;
    int f,s,g,u,d;
    bool bnum[MAX];

    int bfs()
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
                return time;
            }
            if (num + u <= f && !bnum[num+u])
            {
                bnum[num+u] = true;
                q.push(make_pair(num+u,time+1));
            }
            if (num - d > 0 && !bnum[num-d])
            {
                bnum[num-d] = true;
                q.push(make_pair(num-d,time+1)); 
            }
        }
        return -1;
    }

    int main()
    {
         ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


        cin >> f >> s >> g >> u >> d;
        int a = bfs();
        if (a == -1)
            cout << "use the stairs";
        else   
            cout << a;
        return 0;
    }   