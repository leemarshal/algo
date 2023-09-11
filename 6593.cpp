#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r, c;
    cin >> l >> r >> c;
    while(l != 0 && r != 0 && c != 0) {
        char board[30][30][30];
        bool visit[30][30][30] = {};
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    char temp;
                    cin >> temp;
                    if(temp == 'S') {
                        q.push({i, j, k});
                        visit[i][j][k] = true;
                    }
                    else if(temp == '#') visit[i][j][k] = true;
                    board[i][j][k] = temp;
                }
            }
        }
        int dx[6] = {1, -1, 0, 0, 0, 0};//r
        int dy[6] = {0, 0, 1, -1, 0, 0};//c
        int dz[6] = {0, 0, 0, 0, 1, -1};//l
        int last = q.size();
        int cnt = 0;//-1
        bool flag = false;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            last--;
            for(int d = 0; d < 6; d++) {
                int nz = get<0>(cur) + dz[d];
                int nx = get<1>(cur) + dx[d];
                int ny = get<2>(cur) + dy[d];
                if(nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(visit[nz][nx][ny]) continue;
                if(board[nz][nx][ny] == 'E') flag = true;
                q.push({nz, nx, ny});
                visit[nz][nx][ny] = true;
            }
            if(last == 0) {
                cnt++;
                last = q.size();
                if(flag) break;
            }
        }
        if(flag) cout << "Escaped in " << cnt << " minute(s).\n";
        else cout << "Trapped!\n";
        cin >> l >> r >> c;
    }
    return 0;
}
//
// Created by 규북 on 2023/09/11.
//
