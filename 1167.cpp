#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> parent;
vector<int> visit;

pair<int, int> dfs(int cur) {
    pair<int, int> ret = {cur, 0};
    for(auto nxt : adj[cur]) {
        if(parent[cur] == nxt.first || visit[nxt.first]) continue;
        parent[nxt.first] = cur;
        visit[nxt.first] = true;
        pair<int, int> temp = dfs(nxt.first);
        temp.second += nxt.second;
        if(ret.second < temp.second) ret = temp;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin >> v;

    adj.resize(v + 1);
    parent.resize(v + 1, 0);
    visit.resize(v + 1, false);
    for(int i = 0; i < v; i++) {
        int cur;
        cin >> cur;
        do{
            int node, weight;
            cin >> node;
            if(node == -1) break;
            cin >> weight;

            adj[cur].push_back({node, weight});
        } while(true);
    }

    pair<int, int> a;
    pair<int, int> b;
    a = dfs(1);
    parent.clear();
    visit.clear();
    parent.resize(v + 1);
    visit.resize(v + 1, false);
    b = dfs(a.first);
    cout << b.second;
}

//
// Created by leemarshal on 2024-02-27.
//
