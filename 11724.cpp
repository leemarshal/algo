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
    vector<int> v[n + 1];
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> visit(n + 1);
    queue<int> q;
    int cnt = 0;
    q.push(1);
    visit[1] = true;
    bool flag = true;
    while(flag) {
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for(auto i = v[cur].begin(); i < v[cur].end(); i++) {
                int temp = *i;
                if(visit[temp]) continue;
                q.push(temp);
                visit[temp] = true;
            }
        }
        cnt++;
        int i;
        for(i = 2; i <= n; i++) {
            if(!visit[i]) {
                //flag = true;
                q.push(i);
                visit[i] = true;
                break;
            }
        }
        if(q.empty()) flag = false;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/08/28.
//
