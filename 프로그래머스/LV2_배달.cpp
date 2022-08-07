#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2111111111
int dist[51];
vector<pair<int,int> > map[51];

void djikstra()                 // 다익스트라
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,1));            // 비용, 첫번째 노드 넣기 
    dist[1] = 0;                        // 시작 노드의 비용 = 0
    while(!pq.empty())
    {
        int node = pq.top().second;      
        int dis = pq.top().first;         
        pq.pop();
        if (dis > dist[node])           // 큐에 담긴 node까지 거리가 이전에 찾은 거리보다 크다면 skip
            continue;
        for (int i = 0; i < map[node].size();i++)
        {
            int nextnode = map[node][i].first;          
            int nextdist = map[node][i].second + dis;   
            if (nextdist > dist[nextnode])      // 다음 노드까지의 거리가 이전에 찾은 거리보다 크다면 skip
                continue;
            dist[nextnode] = nextdist;
            pq.push(make_pair(nextdist,nextnode));
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i <= N; i++)            // 1번노드부터의 거리를 담을 배열 INF로 초기화 해주기
        dist[i] = INF;
    for (int i = 0; i < road.size(); i++)   
    {

        map[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        map[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
    }
    // djikstra
    djikstra();
    for (int i = 1; i <= N; i++)
    {
       if(dist[i] <= K)          // K 이하 인것만 카운팅 
           answer++;
    }
    return answer;
}