#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, m, n, k, x, y, cnt = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    cin >> t;
    while(t > 0) {
        cin >> m >> n >> k;
        bool board[51][51] = {};
        bool visit[51][51] = {};
        queue<pair<int, int>> q;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            board[x][y] = true;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!board[i][j] || visit[i][j]) continue;
                q.push({i, j});
                visit[i][j] = true;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(!board[nx][ny] || visit[nx][ny]) continue;
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                    }
                }
                cnt++;
            }
        }
        cout << cnt << "\n";
        t--;
        cnt = 0;
    }
    return 0;
}
//
// Created by 규북 on 2023/08/11.
//