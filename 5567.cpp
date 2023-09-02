#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> e[n + 1];
    bool visit[501] = {};
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    visit[1] = true;
    int depth = 0;
    int last = 1;
    while(!q.empty() && depth < 2) {
        int cur = q.front();
        q.pop();
        last--;
        for(auto nxt : e[cur]) {
            if(visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = true;
        }
        if(last == 0) {
            last = q.size();
            depth++;
        }
    }
    int cnt = -1;
    for(int i = 1; i <= n; i++)
        if(visit[i]) cnt++;
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/09/02.
//
