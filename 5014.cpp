#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int f, s, g, u, d; //총, 강호, 스타트링크, 업, 다운
    cin >> f >> s >> g >> u >> d;

    queue<pair<int, int>> q;
    vector<bool> visit(f + 1, false);
    q.push({s, 0});
    visit[s] = true;
    bool flag = false;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        if(cur.first == g) {
            flag = true;
            cout << cur.second;
            break;
        }
        q.pop();
        for(int i = 0; i < 2; i++) {
            int nxt;
            i == 0 ? nxt = cur.first + u : nxt = cur.first - d;
            if(nxt < 1 || nxt > f) continue;
            if(visit[nxt]) continue;
            visit[nxt] = true;
            q.push({nxt, cur.second + 1});
        }
    }
    if(!flag) cout << "use the stairs";
    return 0;
}

//
// Created by 규북 on 2/4/24.
//
