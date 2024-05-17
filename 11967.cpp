#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    int N, M, cnt = 0;
    cin >> N >> M;
    vector<vector<vector<pair<int, int>>>> button(N + 2, vector<vector<pair<int, int>>>(N + 2));
    vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
    vector<vector<bool>> light(N + 2, vector<bool>(N + 2, false));
    for(int i = 0; i < N + 1; i++) {
        visited[0][i] = true;
        visited[N + 1][i] = true;
        visited[i][0] = true;
        visited[i][N + 1] = true;
    }
    int x, y, a, b;
    for(int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        button[x][y].push_back({a, b});
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    light[1][1] = true;
    cnt++;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto bn : button[cur.first][cur.second]) {//현재 위치에서 button을 눌러 킬 수 있는 방에 대하여
            int bx = bn.first;
            int by = bn.second;
            if(light[bx][by]) continue;//이미 켜진 방이라면 continue
            light[bx][by] = true;//불 키기
            cnt++;
            for(int d = 0 ; d < 4; d++) {//원격으로 킨 방이 1.불이 켜지고 2.이미 방문했던 방이랑 연결되면 큐에 추가
                int nx = bx + dx[d];
                int ny = by + dy[d];
                if(!light[nx][ny]) continue;
                if(!visited[nx][ny]) continue;
                q.push({bx, by});
                visited[bx][by] = true;
                break;
            }
        }
        for(int d = 0; d < 4; d++) {//현재 위치에서 방문 가능한 1.불이 켜지고 2. 방문하지 않은 방이면 큐에 추가
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(visited[nx][ny]) continue;
            if(!light[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    cout << cnt;
    return 0;
}

//
// Created by 규북 on 5/18/24.
//
