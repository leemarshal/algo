#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char board[100][100] = {};
    bool visit[100][100] = {};
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++)
            board[i][j] = s[j];
    }
    queue<pair<int, int>> q;
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j]) continue;
            q.push({i, j});
            visit[i][j] = true;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visit[nx][ny]) continue;
                    if(board[cur.first][cur.second] != board[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
                if(board[cur.first][cur.second] == 'G') board[cur.first][cur.second] = 'R';
            }
            cnt1++;
        }
    }
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            visit[i][j] = false;
    int cnt2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j]) continue;
            q.push({i, j});
            visit[i][j] = true;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visit[nx][ny]) continue;
                    if(board[cur.first][cur.second] != board[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
            cnt2++;
        }
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}
//
// Created by 규북 on 2023/08/29.
//
