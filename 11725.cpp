#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> p(n + 1);
    queue<int> q;
    int n1, n2;
    for(int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    q.push(1);
    p[1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto& a : adj[cur]) {
            if(a == p[cur]) continue;
            q.push(a);
            p[a] = cur;
        }
    }
    for(int i = 2; i <= n; i++)
        cout << p[i] << "\n";

    return 0;
}
//
// Created by 규북 on 1/22/24.
//
