#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    cin >> n >> m; //세로, 가로
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<int>> result(n, vector<int>(m, 0));
    //vector<vector<bool>> visited;

    int a, rowStart, colStart;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a;
            board[i][j] = a;
            if(a == 2) {
                result[i][j] = 0;
                rowStart = i;
                colStart = j;
            }
            else if(a == 1) result[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({rowStart, colStart});
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //index out of bounds
            if(board[nx][ny] == 0 || result[nx][ny] != -1) continue; //갈 수 없거나, 이미 방문 했다면
            result[nx][ny] = result[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    for(auto& res : result) {
        for(auto r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }

    return 0;
}
//
// Created by 규북 on 5/11/24.
//
