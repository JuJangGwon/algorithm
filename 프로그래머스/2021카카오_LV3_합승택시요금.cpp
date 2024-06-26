#include <string>
#include <vector>
#include <queue>
#include <memory.h>

#define INF 2111111111
// * floid / djikstra
using namespace std;

int path[201];
int cost[201];
int cost1[201];
int cost2[201];

vector<pair<int,int> > map[201];


void djikstra(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    cost[st] = 0;
    printf("%d\n",st);
    pq.push(make_pair(0,st));
    while (!pq.empty())
    {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        if (cost[now_node] < now_cost)
            continue;
        for (int i = 0; i < map[now_node].size();i++)
        {
            int next_node = map[now_node][i].first;
            int next_cost = map[now_node][i].second + now_cost;
            if (cost[next_node] > next_cost)
            {
                cost[next_node] = next_cost;
                path[next_node] = now_node;
                pq.push(make_pair(next_cost,next_node));
            }
        }
    }
}
void djikstra1(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    cost1[st] = 0;
    pq.push(make_pair(0,st));
    while (!pq.empty())
    {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        if (cost1[now_node] < now_cost)
            continue;
        for (int i = 0; i < map[now_node].size();i++)
        {
            int next_node = map[now_node][i].first;
            int next_cost = map[now_node][i].second + now_cost;
            if (cost1[next_node] > next_cost)
            {
                cost1[next_node] = next_cost;
                path[next_node] = now_node;
                pq.push(make_pair(next_cost,next_node));
            }
        }
    }
}
void djikstra2(int st)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    cost2[st] = 0;
    pq.push(make_pair(0,st));
    while (!pq.empty())
    {
        int now_node = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();
        if (cost2[now_node] < now_cost)
            continue;
        for (int i = 0; i < map[now_node].size();i++)
        {
            int next_node = map[now_node][i].first;
            int next_cost = map[now_node][i].second + now_cost;
            if (cost2[next_node] > next_cost)
            {
                cost2[next_node] = next_cost;
                path[next_node] = now_node;
                pq.push(make_pair(next_cost,next_node));
            }
        }
    }
}

void cclear(int a)
{
    for (int i = 1; i <= a; i++)            // INF 초기화
    {
        cost1[i] = INF;
        cost2[i] = INF;
        cost[i] = INF;
        path[i] = -1;
    }
}
    vector<int> _track;

    int answer = 0;

void track_path(int st, int ed)
{
    int temp = ed;
    
    while (temp != -1)
    {
        _track.push_back(temp);
        temp = path[temp];
    }
    for (int i = _track.size()-1; i > -1; i--)
    {
        for (int j = 0; j < map[_track[i]].size(); j++)
        {
            if (map[_track[i]][j].first == _track[i-1])
            {
                map[_track[i]][j].second = 0;
                break;
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    cclear(n);
    for (int i = 0; i < fares.size(); i++)           
    {
        map[fares[i][0]].push_back(make_pair(fares[i][1],fares[i][2]));
        map[fares[i][1]].push_back(make_pair(fares[i][0],fares[i][2]));
    }

    djikstra1(a);
    djikstra2(b);
    djikstra(s);
    
    int answer = 99999999;
    for(int i = 1; i <= n; i++)
    {
        answer = answer < cost[i]+cost1[i]+cost2[i] ? answer : cost[i]+cost1[i]+cost2[i];
    }
    return answer;
}