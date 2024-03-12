#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

vector<vector<array<int, 2>>> adj;//가중치 노드 쌍
vector<int> dist;

void dijkstra(int cur) {
    for(auto& d : dist)
        d = 2e+8;
    dist[cur] = 0;
    priority_queue<array<int,2>, vector<array<int, 2>>, greater<array<int, 2>>> pq; // 가중치, 노드 쌍
    pq.push({0, cur});
    while(!pq.empty()) {
        int curDist = pq.top()[0];
        int curNode = pq.top()[1];
        pq.pop();
        for(auto nxt : adj[curNode]) {
            if(curDist + nxt[0] < dist[nxt[1]]) {
                dist[nxt[1]] = curDist + nxt[0];
                pq.push({dist[nxt[1]], nxt[1]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1);
    int n1, n2, w;
    for(int i = 0; i < m; i++) {
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({w, n2});
        adj[n2].push_back({w, n1});
    }
    int v1, v2;
    cin >> v1 >> v2;
    int v1_s, v1_n, v2_s, v2_n, v1_v2;
    dijkstra(v1);
    v1_s = dist[1];
    v1_v2 = dist[v2];
    v1_n = dist[n];
    dijkstra(v2);
    v2_s = dist[1];
    v2_n = dist[n];

    int ret1 = v1_s + v1_v2 + v2_n;
    int ret2 = v2_s + v1_v2 + v1_n;
    if(ret1 > 2e+8 || ret2 > 2e+8) cout << -1;
    else cout << (ret1 < ret2 ? ret1 : ret2);
    return 0;
}
//
// Created by 규북 on 3/12/24.
//
