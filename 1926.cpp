#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, cnt = 0, area, max = 0;
    cin >> n >> m;
    bool board[501][501];
    bool visit[501][501] = {};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visit[i][j] || !board[i][j]) continue;
            q.push({i, j});
            visit[i][j] = true;
            cnt++;
            area = 0;
            while(!q.empty()) {
                area++;
                pair<int, int> cur = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(visit[nx][ny] || !board[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
            if(area > max) max = area;
        }
    }
    cout << cnt << "\n" << max;
    return 0;
}
//
// Created by 규북 on 2023/08/06.
//
