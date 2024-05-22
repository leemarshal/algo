#include <iostream>
#include <vector>
using namespace std;

struct Tetromino {
    std::vector<std::vector<int>> shape;
    int rows;
    int cols;

    Tetromino(const vector<std::vector<int>>& s) : shape(s), rows(s.size()), cols(s[0].size()) {}
};

// 테트로미노 정의 함수
std::vector<Tetromino> createTetrominos() {
    std::vector<Tetromino> tetrominos;

    // 테트로미노 모양들
    tetrominos.push_back(Tetromino({{1, 1, 1, 1}}));        // t1
    tetrominos.push_back(Tetromino({{1}, {1}, {1}, {1}}));  // t2
    tetrominos.push_back(Tetromino({{1, 1}, {1, 1}}));      // t3

    tetrominos.push_back(Tetromino({{1, 0}, {1, 0}, {1, 1}})); // t4
    tetrominos.push_back(Tetromino({{1, 1, 1}, {1, 0, 0}}));   // t5
    tetrominos.push_back(Tetromino({{1, 1}, {0, 1}, {0, 1}})); // t6
    tetrominos.push_back(Tetromino({{0, 0, 1}, {1, 1, 1}}));   // t7

    tetrominos.push_back(Tetromino({{0, 1}, {0, 1}, {1, 1}})); // t8
    tetrominos.push_back(Tetromino({{1, 0, 0}, {1, 1, 1}}));   // t9
    tetrominos.push_back(Tetromino({{1, 1}, {1, 0}, {1, 0}})); // t10
    tetrominos.push_back(Tetromino({{1, 1, 1}, {0, 0, 1}}));   // t11

    tetrominos.push_back(Tetromino({{1, 0}, {1, 1}, {0, 1}})); // t12
    tetrominos.push_back(Tetromino({{0, 1, 1}, {1, 1, 0}}));   // t13
    tetrominos.push_back(Tetromino({{0, 1}, {1, 1}, {1, 0}})); // t14
    tetrominos.push_back(Tetromino({{1, 1, 0}, {0, 1, 1}}));   // t15

    tetrominos.push_back(Tetromino({{1, 0}, {1, 1}, {1, 0}})); // t16
    tetrominos.push_back(Tetromino({{1, 1, 1}, {0, 1, 0}}));   // t17
    tetrominos.push_back(Tetromino({{0, 1}, {1, 1}, {0, 1}})); // t18
    tetrominos.push_back(Tetromino({{0, 1, 0}, {1, 1, 1}}));   // t19

    return tetrominos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<Tetromino> tetrominos = createTetrominos();

    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N + 3, vector<int>(M + 3, 0));
    for(int n = 0; n < N; n++) {
        for(int m = 0; m < M; m++) {
            cin >> board[n][m];
        }
    }
    int answer = 0;
    for(int n = 0; n < N; n++) {
        for(int m = 0; m < M; m++) {
            for(auto& tetromino : tetrominos) {
                int sum = 0;
                for(int r = 0; r < tetromino.rows; r++) {
                    for(int c = 0; c < tetromino.cols; c++) {
                        sum += tetromino.shape[r][c] * board[n + r][m + c];
                    }
                }
                if(sum > answer) answer = sum;
            }
        }
    }
    cout << answer;
    return 0;
}
//
// Created by 규북 on 5/22/24.
//
