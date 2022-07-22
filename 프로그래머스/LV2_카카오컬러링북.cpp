#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
bool visited[101][101];
int max_size_of_one_area = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(int x, int y, vector<vector<int> > p)
{
    int time = 1;
    queue<pair<int,pair<int,int > > > q;
    q.push(make_pair(p[y][x],make_pair(x,y)));
    visited[y][x] = true;
    while (!q.empty())
    {
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        int same = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xxx = xx+dx[i];
            int yyy = yy+dy[i];
            if (!(xxx >= 0 && yyy >= 0 && xxx < p[0].size() && yyy < p.size() && !visited[yyy][xxx]))
                continue;
            if (p[yyy][xxx] == same)
            {
                visited[yyy][xxx] = true;
                q.push(make_pair(p[yyy][xxx],make_pair(xxx,yyy)));
                time++;
            }
        }
    }
    return time;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    //memset(visited,false,sizeof(visited));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++)
    {       
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && picture[i][j] != 0)
            {
                max_size_of_one_area = max(max_size_of_one_area, bfs(j,i,picture));
                number_of_area++;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}