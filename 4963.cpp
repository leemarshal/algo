#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short h, w;
    cin >> w >> h;
    int dx[8] = {1, -1, 0, 0, -1, 1, -1, 1};
    int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    while(w != 0 && h != 0) {
        bool board[50][50];
        bool visit[50][50] = {};
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> board[i][j];
                if(!board[i][j]) visit[i][j] = true;
            }
        }
        queue<pair<short, short>> q;
        int cnt = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(visit[i][j]) continue;
                q.push({i, j});
                visit[i][j] = true;
                while(!q.empty()) {
                    pair<short, short> cur = q.front();
                    q.pop();
                    for(int d = 0; d < 8; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if(visit[nx][ny]) continue;
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                    }
                }
                cnt++;
            }
        }
        cout << cnt << "\n";
        cin >> w >> h;
    }
    return 0;
}
//
// Created by 규북 on 2023/09/12.
//
