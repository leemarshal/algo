#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, jsize, fsize, day = 0;
    char temp;
    cin >> r >> c;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0,-1};
    char board[1001][1001];
    bool visit[1001][1001] = {};
    bool Jvisit[1001][1001] = {};
    queue<pair<int, int>> J;
    queue<pair<int, int>> F;
    bool flag = false;
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> temp;
            board[i][j] = temp;
            if(temp == '.') continue;
            if(temp == 'J') {
                J.push({i, j});
                Jvisit[i][j] = true;
                if(i == 0 || i == r - 1 || j == 0 || j == c - 1)
                    flag = true;
                continue;
            }
            else if(temp == 'F') F.push({i, j});
            visit[i][j] = true;
        }
    }
    fsize = F.size();
    jsize = J.size();

    while(!(F.empty() && J.empty()) && !flag) {
        while(fsize > 0) {
            pair<int, int> cur = F.front();
            F.pop();
            fsize--;
            for(int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(visit[nx][ny]) continue;
                board[nx][ny] = 'F';
                visit[nx][ny] = true;
                F.push({nx, ny});
            }
        }
        fsize = F.size();
        while(jsize > 0) {
            pair<int, int> cur = J.front();
            J.pop();
            jsize--;
            for(int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(Jvisit[nx][ny] || visit[nx][ny]) continue;
                board[nx][ny] = 'J';
                Jvisit[nx][ny] = true;
                J.push({nx, ny});
                if(nx == 0 || nx == r - 1 || ny == 0 || ny == c - 1) {
                    flag = true;
                    break;
                }
            }
        }
        jsize = J.size();
        day ++;
    }
    if(flag) {
        day++;
        cout << day;
    }
    else cout << "IMPOSSIBLE";
    return 0;
}
//
// Created by 규북 on 2023/08/09.
//