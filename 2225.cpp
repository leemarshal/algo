#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int board[201][201] = {};
    for(int i = 0; i <= n; i++)
        board[1][i] = 1;
    for(int i = 1; i <= k; i++)
        board[i][0] = 1;
    for(int i = 2; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            board[i][j] = (board[i][j - 1] + board[i - 1][j]) % 1000000000;
        }
    }
    cout << board[k][n];
    return 0;
}
//
// Created by 규북 on 2023/09/03.
//
