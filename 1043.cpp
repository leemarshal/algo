#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, truthSize, partySize;
    cin >> n >> m;
    
    vector<bool> visit(n + 1, false);
    //vector<vector<int>> adj(n + 1);
    vector<unordered_set<int>> adj(n + 1);
    
    cin >> truthSize;
    vector<int> truthHolder(truthSize);
    for(int i = 0; i < truthSize; i++) {
        cin >> truthHolder[i];
        visit[truthHolder[i]] = true;
    }

    vector<vector<int>> party(m);
    for(int i = 0; i < m; i++) {
        cin >> partySize;
        int temp;
        for(int j = 0; j < partySize; j++) {
            cin >> temp;
            party[i].push_back(temp);
        }
        for(int j = 0; j < partySize; j++) {
            for(int k = 0; k < partySize; k++) {
                if(j == k) continue;
                adj[party[i][j]].insert(party[i][k]);
            }
        }
    }
    
    queue<int> q;
    for(int i = 0; i < truthSize; i++) {
        q.push(truthHolder[i]);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto a : adj[cur]) {
                if(visit[a]) continue;
                q.push(a);
                visit[a] = true;
            }
        }
    }

    if(truthSize == 0) {
        cout << m;
        return 0;
    }
    for(auto& p : party) {
        for(auto person : p) {
            if(visit[person]) {
                m--;
                break;
            }
        }
    }
    cout << m;
    return 0;
}

//
// Created by 규북 on 2/26/24.
//
