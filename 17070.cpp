#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <array>

#define X first
#define Y second

using namespace std;

int dx[3][3][2] = {{{1, 1}, {1, 1}, {-1, -1}},
                   {{0, 0}, {0, 1}, {-1, -1}},
                   {{1, 1}, {1, 0}, {1, 1}}};
int dy[3][3][2] = {{{0, 0}, {0, 1}, {-1, -1}},
                   {{1, 1}, {1, 1}, {-1, -1}},
                   {{1, 0}, {1, 1}, {1, 1}}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> board(n + 2, vector<int>(n + 2, 0));
    for(int i = 0; i < n + 2; i++) {
        board[0][i] = 1;
        board[i][0] = 1;
        board[n + 1][i] = 1;
        board[i][n + 1] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    int cnt = 0;
    queue<array<pair<int, int>, 2>> q;
    q.push({{{1, 1}, {2, 1}}});
    int type;//0: 가로, 1: 세로, 2: 대각선
    while(!q.empty()) {
        pair<int, int> cur1 = q.front()[0];
        pair<int, int> cur2 = q.front()[1];
        q.pop();
        if((cur1.X == n && cur1.Y == n) || cur2.X == n && cur2.Y == n) {
            cnt++;
            continue;
        }

        if(cur1.X == cur2.X) type = 1;
        else if(cur1.Y == cur2.Y) type = 0;
        else type = 2;

        for(int d = 0; d < 3; d++) {
            if(dx[type][d][0] == -1) continue;
            pair<int, int> nxt1 = cur1;
            pair<int, int> nxt2 = cur2;
            nxt1.X += dx[type][d][0];
            nxt1.Y += dy[type][d][0];
            nxt2.X += dx[type][d][1];
            nxt2.Y += dy[type][d][1];
            if(board[nxt2.Y][nxt2.X] == 1) continue;
            if(nxt1.X != nxt2.X && nxt1.Y != nxt2.Y &&
            (board[nxt1.Y + 1][nxt1.X] == 1 || board[nxt1.Y][nxt1.X + 1] == 1))
                continue;
            q.push({{{nxt1.X, nxt1.Y}, {nxt2.X, nxt2.Y}}});
        }
    }
    cout << cnt;
}

//
// Created by 규북 on 3/22/24.
//
