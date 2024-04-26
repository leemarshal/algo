#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra(int cur) {
    vector<bool> visited(dist.size(), false);
    for(auto& d : dist) {
        d = 4e+7;
    }
    dist[cur] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur});
    while(!pq.empty()) {
        int curD = pq.top().first;
        int curN = pq.top().second;
        pq.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        for(auto nxt : adj[curN]) {
            if(curD + nxt.first < dist[nxt.second]) {
                dist[nxt.second] = curD + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, e, k, a, b, w;
    cin >> v >> e >> k;
    adj.resize(v + 1);
    dist.resize(v + 1);

    for(int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }

    dijkstra(k);
    for(int i = 1; i <= v; i++) {
        if(dist[i] > 3e+6) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
//
// Created by 규북 on 4/26/24.
//
