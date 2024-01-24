#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<int> ans;
vector<int> p;
void dfs(int cur) {
    for(int nxt : adj[cur]) {
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
        ans[cur] += ans[nxt];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;
    adj.resize(n + 1);
    ans.resize(n + 1, 1);
    p.resize(n + 1);
    for(int i = 1; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    p[r] = 0;
    dfs(r);
    for(int i = 0; i < q; i++) {
        int node;
        cin >> node;
        cout << ans[node] << "\n";
    }
}

//
// Created by 규북 on 1/25/24.
//
