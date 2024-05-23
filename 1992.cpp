#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

string solve(int rs, int cs, int len) {
    if(len == 1) {
        return to_string(board[rs][cs]);
    }
    string result[4];
    len /= 2;
    result[0] = solve(rs, cs, len);
    result[1] = solve(rs, cs + len, len);
    result[2] = solve(rs + len, cs, len);
    result[3] = solve(rs + len, cs + len, len);

    if(result[0].length() == 1 && result[0] == result[1] && result[1] == result[2] && result[2] == result[3]) return result[0];

    return "(" + result[0] + result[1] + result[2] + result[3] + ")";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    board.resize(N, vector<int>(N));
    for(int n = 0; n < N; n++) {
        string str;
        cin >> str;
        for(int i = 0; i < N; i++) {
            board[n][i] = str[i] - '0';
        }
    }

    cout << solve(0, 0, N);
    N = N;
    return 0;
}

//
// Created by 규북 on 5/23/24.
//
