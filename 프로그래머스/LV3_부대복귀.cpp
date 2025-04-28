#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<int> arr[100001];


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    int dist[100001];
    memset(dist,9999999,sizeof(int) * 100001);
    
    for (int i = 0; i < roads.size(); i++){
        arr[roads[i][0]].push_back(roads[i][1]);
        arr[roads[i][1]].push_back(roads[i][0]);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    
    pq.push(make_pair(0,destination));
    dist[destination] = 0;
    while(!pq.empty()){
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        if (a > dist[b]) 
            continue;
        for (int i = 0; i < arr[b].size(); i++){
           if(a + 1 < dist[arr[b][i]]){
               pq.push(make_pair(a+1,arr[b][i]));
               dist[arr[b][i]] = a+1;
           }  
        }
        
    }
    for (int i = 0; i < sources.size(); i++){
       
        answer.push_back(dist[sources[i]] > 9999999 ? -1 : dist[sources[i]]);
    }
    return answer;
}