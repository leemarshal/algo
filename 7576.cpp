#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, last, day = -1;
    int board[1001][1001];
    bool visit[1001][1001] = {};
    cin >> n >> m;
    int cnt = n * m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           cin >> board[i][j];
           if(board[i][j] == 0) continue;
           else if(board[i][j] == 1) q.push({i, j});
           visit[i][j] = true;
           cnt--;
        }
    }
    last = q.size();
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        last--;
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(visit[nx][ny]) continue;
            board[nx][ny] = 1;
            visit[nx][ny] = true;
            q.push({nx, ny});
            cnt--;
        }
        if(last == 0) {
            day++;
            last = q.size();
        }
    }
    if(cnt == 0) cout << day;
    else cout << -1;
    return 0;
}
//
// Created by 규북 on 2023/08/08.
//

