#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    while(true) {
        int n, m, t = 0;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        vector<bool> visit(n + 1, false);
        vector<vector<int>> adj(n + 1);
        vector<int> p(n + 1, 0);
        for(int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        for(int i = 1; i <= n; i++) {
            if(visit[i]) continue;
            queue<int> q;
            q.push(i);
            p[i] = 0;
            visit[i] = true;
            bool flag = false;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                if(adj[cur].empty()) continue;
                for(auto a : adj[cur]) {
                    if(a == p[cur]) continue;
                    if(visit[a]) flag = true;
                    else {
                        q.push(a);
                        p[a] = cur;
                        visit[a] = true;
                    }
                }
            }
            if(!flag) t++;
        }
        if(t > 1) cout << "Case " << tc << ": A forest of " << t << " trees." << "\n";

        else if(t == 1) cout << "Case " << tc << ": There is one tree." << "\n";
        else cout << "Case " << tc << ": No trees." << "\n";
        tc++;
    }
    return 0;
}

//
// Created by 규북 on 1/24/24.
//
