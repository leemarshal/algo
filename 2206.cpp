#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <string>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n,vector<int>(m));
    vector<vector<int>> v1(n,vector<int>(m, -1));
    vector<vector<int>> v0(n,vector<int>(m, -1));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            b[i][j] = s[j] - '0';
        }
    }
    queue<array<int, 3>> q;
    q.push({0, 0, 1});
    v0[0][0] = 1;
    v1[0][0] = 1;
    while(!q.empty()) {
        array<int, 3> cur = q.front();
        q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = cur[0] + dx[d], ny = cur[1] + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(cur[2] == 1) {
                if(b[nx][ny] == 0 && v1[nx][ny] == -1) {
                    q.push({nx, ny, 1});
                    v1[nx][ny] = v1[cur[0]][cur[1]] + 1;
                }
                else if(b[nx][ny] == 1) {
                    int nnx = nx + dx[d], nny = ny + dy[d];
                    if(nnx < 0 || nnx >= n || nny < 0 || nny >= m) continue;
                    if(!(b[nnx][nny] == 0 && v0[nnx][nny] == -1)) continue;
                    q.push({nnx, nny, 0});
                    v0[nnx][nny] = v1[cur[0]][cur[1]] + 2;
                }
            }
            else if(cur[2] == 0) {
                if(b[nx][ny] == 1) continue;
                if(v0[nx][ny] > -1) continue;
                q.push({nx, ny, 0});
                v0[nx][ny] = v0[cur[0]][cur[1]] + 1;
            }
        }
    }
    if(v1[n - 1][m - 1] == -1 && v0[n - 1][m - 1] == -1) cout << -1;
    else if(v1[n - 1][m - 1] == -1 || v0[n - 1][m - 1] == -1) {
        int ret = v1[n - 1][m - 1] > v0[n - 1][m - 1] ? v1[n - 1][m - 1] : v0[n - 1][m - 1];
        cout << ret;
    }
    else {
        int ret = v1[n - 1][m - 1] < v0[n - 1][m - 1] ? v1[n - 1][m - 1] : v0[n - 1][m - 1];
        cout << ret;
    }
    return 0;
}

//
// Created by 규북 on 2/5/24.
//
