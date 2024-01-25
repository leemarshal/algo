#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> p;
vector<int> d;
void dfs(int cur) {
    for(auto& nxt : adj[cur]) {
        if(p[cur].first == nxt.first) continue;
        p[nxt.first].first = cur;
        p[nxt.first].second = nxt.second;
        d[nxt.first] = d[cur] + 1;
        dfs(nxt.first);
    }
}

void sol() {
    int a, b, pa, pb, da, db;
    cin >> a >> b;
    if(a == b) {
        cout << 0;
        return;
    }
    /*
    pa = p[a].first;
    da = p[a].second;
    pb = p[b].first;
    db = p[b].second;
    */
    pa = a;
    pb = b;
    da = 0;
    db = 0;
    while(pa != pb) {
        int sub = d[pa] - d[pb];
        if(d[pa] > d[pb])
            for(int i = 0; i < sub; i++) {
                da += p[pa].second;
                pa = p[pa].first;
            }
        else if(d[pa] < d[pb])
            for(int i = 0; i > sub; i--) {
                db += p[pb].second;
                pb = p[pb].first;
            }
        else {
            db += p[pb].second;
            pb = p[pb].first;
            da += p[pa].second;
            pa = p[pa].first;
        }
    }
    cout << da + db << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    p.resize(n + 1);
    d.resize(n + 1);
    for(int i = 1; i < n; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;
        adj[a].push_back({b, dist});
        adj[b].push_back({a, dist});
    }
    p[1] = {0, 0};
    d[1] = 1;
    dfs(1);
    for(int i = 0; i < m; i++)
        sol();
    return 0;
}
//
// Created by 규북 on 1/25/24.
//
