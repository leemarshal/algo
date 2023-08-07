#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cnt = 0, last = 0;
    bool flag = false;
    cin >> n >> m;
    queue<pair<int, int>> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool board[101][101];
    bool visit[101][101] = {};
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '1') board[i][j] = true;
            else board[i][j] = false;
        }
    }
    q.push({0, 0});
    visit[0][0] = true;
    last = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        last--;
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx  < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] || !board[nx][ny]) continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
            if(nx == n-1 && ny == m-1) {
                flag = true;
                break;
            }
        }
        if(flag) {
            cnt += 2;
            break;
        }
        else if(last == 0) {
            last = q.size();
            cnt++;
        }
    }
    if(flag) cout << cnt;
    else cout << 0;
    return 0;
}
//
// Created by 규북 on 2023/08/07.
//
