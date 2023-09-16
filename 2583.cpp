#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k;
    cin >> m >> n >> k;
    int board[100][100];
    bool visit[100][100] = {};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 1;
        }
    }
    int x1, x2, y1, y2;
    for (int kk = 0; kk < k; kk++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                board[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }
    int cnt = 0;
    queue<pair<int, int>> q;
    vector<int> v;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) continue;
            cnt++;
            int s = 0;
            q.push({i, j});
            visit[i][j] = true;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                s++;
                for (int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (visit[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << "\n";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/16.
//
