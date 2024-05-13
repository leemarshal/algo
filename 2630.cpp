#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board;
int cntW = 0, cntB = 0;
char dfs(int len, int x, int y) {
    if(len == 1) {
        if(board[x][y] == 0) return 'w';
        else return 'b';
    }
    char result[4];
    len /= 2;
    result[0] = dfs(len, x, y);//2사분면
    result[1] = dfs(len, x + len, y);//1사분면
    result[2] = dfs(len, x, y + len);//3사분면
    result[3] = dfs(len, x + len, y + len);//4사분면

    if(result[0] == result[1] && result[1] == result[2] && result[2] == result[3]) {
        return result[0];
    }

    for(int i = 0; i < 4; i++) {
        if(result[i] == 'm') continue;
        if(result[i] == 'w') cntW++;
        else cntB++;
    }
    return 'm';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    board.resize(N, vector<int>(N, 0));

    for(auto& row : board) {
        for(auto& b : row) {
            cin >> b;
        }
    }

    int result = dfs(N, 0, 0);
    if(result == 'w') cntW++;
    else if(result == 'b') cntB++;
    cout << cntW << "\n" << cntB;
    return 0;
}
//
// Created by 규북 on 5/13/24.
//
