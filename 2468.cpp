#include <iostream>
#include <queue>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    short board[101][101];
    set<short> uniq;
    short temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> temp;
            board[i][j] = temp;
            uniq.insert(temp);
        }
    }
    int count = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int safe = 0;
    int answer = 0;
    for(auto it = uniq.begin(); it !=uniq.end() && count < uniq.size() - 1; it++, count++) {
        temp = *it;
        bool visit[101][101] = {};
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visit[i][j]) continue;
                if(board[i][j] <= temp) continue;
                q.push({i, j});
                visit[i][j] = true;
                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for(int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(visit[nx][ny]) continue;
                        if(board[nx][ny] <= temp) continue;
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                    }
                }
                safe++;
            }
        }
        if(safe > answer) answer = safe;
        safe = 0;
    }
    if(answer == 0) answer = 1;
    cout << answer;
    return 0;
}
//
// Created by 규북 on 2023/09/07.
//
