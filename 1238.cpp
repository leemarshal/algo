#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int n, m, x;
const int INF = 1e9 + 7;

void dijkstra(int src, const vector<vector<int>>& adj,
              vector<bool>& visited,
              vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;

        for(int v = 1; v <= n; v++) {
            if(visited[v] || adj[u][v] == 0) continue;
            if(dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<vector<int>> revAdj(n + 1, vector<int>(n + 1));

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        revAdj[v][u] = w;
    }

    vector<bool> visited(n + 1, false);
    vector<bool> revVisited(n + 1, false);
    vector<int> dist(n + 1, INF);
    vector<int> revDist(n + 1, INF);

    dijkstra(x, adj, visited, dist);
    dijkstra(x, revAdj, revVisited, revDist);

    for(int i = 1; i <= n; i++) {
        dist[i] += revDist[i];
    }
    dist.erase(dist.begin());
    sort(dist.begin(), dist.end(), greater<int>());

    cout << dist[0];
}