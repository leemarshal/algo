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
    int N, M, rowStart, colStart, cnt;
    char input;
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> input;
            board[i][j] = input;
            if(input == 'I') {
                rowStart = i;
                colStart = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({rowStart, colStart});
    visited[rowStart][colStart] =true;
    cnt = 0;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == 'X' || visited[nx][ny]) continue;
            if(board[nx][ny] == 'P') cnt++;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    if(cnt == 0) cout << "TT";
    else cout << cnt;
    
    return 0;
}
//
// Created by 규북 on 5/15/24.
//
