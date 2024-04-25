#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
vector<vector<pair<int, int>>> edge;
vector<long> dist;

void dijkstra(int cur) {
    vector<bool> visited(dist.size(), false);
    for(auto& d : dist) {
        d = 2e+10;
    }
    dist[cur] = 0;
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    pq.push({0, cur});
    while(!pq.empty()) {
        long curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (visited[curNode]) continue; // 이미 방문한 노드라면 스킵
        visited[curNode] = true; // 노드 방문 표시
        for(auto nxt : edge[curNode]) {
            if(curDist + nxt.second < dist[nxt.first]) {
                dist[nxt.first] = curDist + nxt.second;
                pq.push({dist[nxt.first], nxt.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edge.resize(n + 1);
    dist.resize(n + 1);
    int a, b, w;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edge[a].push_back({b, w});
    }
    cin >> a >> b;
    dijkstra(a);
    cout << dist[b];
}

//
// Created by 규북 on 4/25/24.
//
