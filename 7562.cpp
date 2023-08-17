#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, x, y;
    int dx[4] = {-2, -1, 2, 1};
    int dy[8] = {-1, 1, -2, 2};
    cin >> T;
    for(int t = 0; t < T; t++) {
        queue<pair<int, int>> q;
        bool visit[300][300] = {};
        bool flag = false;
        int cnt = 0, last = 1;
        cin >> n;
        cin >> x >> y;
        q.push({x, y});
        visit[x][y] = true;
        cin >> x >> y;
        if(q.front().first == x && q.front().second == y) {
            flag = true;
            cnt = -1;
        }
        while(!q.empty() && !flag) {
            pair<int, int> cur = q.front();
            q.pop();
            last--;
            for(int i = 0; i < 4; i++) {
                int jtemp = (i * 2) % 4;
                for(int j = jtemp; j < jtemp + 2; j++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[j];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visit[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                    if(nx == x && ny == y) flag = true;
                }
            }
            if(!flag && last == 0) {
                last = q.size();
                cnt++;
            }
        }
        if(flag) {
            cnt++;
            cout << cnt << "\n";
        }
    }
    return 0;
}
//
// Created by 규북 on 2023/08/17.
//
