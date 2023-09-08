#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int board[25][25] = {};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    bool visit[25][25] = {};
    string temp;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < n; j++) {
            board[i][j] = temp[j];
            if(temp[j] == '0') visit[i][j] = true;
        }
    }
    int cnt = 0;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j]) continue;
            q.push({i, j});
            int size = 1;
            visit[i][j] = true;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(visit[nx][ny]) continue;
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                    size++;
                }
            }
            cnt++;
            v.push_back(size);
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << "\n";
    for(int value : v)
        cout << value << "\n";
    return 0;
}
//
// Created by 규북 on 2023/09/08.
//
