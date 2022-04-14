#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int map[26][26];
int used[26][26];
int ovo;
int dx[4] = {0, 0 , 1 , -1};
int dy[4] = {1, -1, 0 , 0};

void dfs(int x, int y)
{
    used[y][x] = 1;
    ovo++;
    for (int i = 0; i < 4; i++)
    {
        int dxx = x + dx[i];
        int dyy = y + dy[i];

        if (dxx >= 1 && dxx <= num && dyy >=1 && dyy <= num && map[dyy][dxx] == 1 && used[dyy][dxx] == false)
        {
            dfs(dxx,dyy);
        }
    }
}

int main()
{
    vector<int> oa;
    cin.tie(NULL);

    cin >> num;
    for (int i = 1; i<= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            int x;
            scanf("%1d",&x);
            map[i][j] = x; 
        }
    }
    for (int i = 1; i<= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (map[i][j] == 1 && used[i][j] == false)
            {
                ovo = 0;
                dfs(j,i);
                oa.push_back(ovo);
            }
        }
    }
    cout << oa.size() << "\n";
    sort(oa.begin(),oa.end());
    for (int i = 0; i < oa.size(); i++)
    {
        cout << oa[i] << "\n";
    }
    return 0;
}