#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, n, m, temp, g = 0;
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    cin >> m >> n >> h;//[h][n][m]
    int board[100][100][100] = {};
    bool visit[100][100][100] = {};
    queue<tuple<int, int, int>> q;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> temp;
                g++;
                if(temp == 0) continue;
                else if(temp == 1) q.push({i, j, k});
                else if(temp == -1) cnt++;
                board[i][j][k] = temp;
                visit[i][j][k] = true;
            }
        }
    }
    cnt = h * n * m - cnt;
    int last, day = -1;
    last = q.size();

    while(!q.empty()) {
        auto [curH, curN, curM] = q.front();
        q.pop();
        cnt--;
        last--;
        for(int dir = 0; dir < 6; dir++) {
            int nx = curN + dx[dir];
            int ny = curM + dy[dir];
            int nz = curH + dz[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(visit[nz][nx][ny]) continue;
            visit[nz][nx][ny] = true;
            q.push({nz, nx, ny});
            board[nz][nx][ny] = 1;
        }
        if(last == 0) {
            last = q.size();
            day++;
        }
    }
    if(cnt == 0) cout << day;
    else cout << "-1";
    return 0;
}
//
// Created by 규북 on 2023/08/25.
//
