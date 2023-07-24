#include <iostream>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, result = 32;
    cin >> n >> m;
    char **map = new char *[n];
    for (int i = 0; i < n; i++) {
        map[i] = new char[m];
    }
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
        }
    }
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < 8; k = k + 2) {
                if(map[i+k][j+0] != 'B') cnt1++;
                if(map[i+k][j+1] != 'W') cnt1++;
                if(map[i+k][j+2] != 'B') cnt1++;
                if(map[i+k][j+3] != 'W') cnt1++;
                if(map[i+k][j+4] != 'B') cnt1++;
                if(map[i+k][j+5] != 'W') cnt1++;
                if(map[i+k][j+6] != 'B') cnt1++;
                if(map[i+k][j+7] != 'W') cnt1++;
            }
            for (int k = 1; k < 8; k = k + 2) {
                if(map[i+k][j+0] == 'B') cnt1++;
                if(map[i+k][j+1] == 'W') cnt1++;
                if(map[i+k][j+2] == 'B') cnt1++;
                if(map[i+k][j+3] == 'W') cnt1++;
                if(map[i+k][j+4] == 'B') cnt1++;
                if(map[i+k][j+5] == 'W') cnt1++;
                if(map[i+k][j+6] == 'B') cnt1++;
                if(map[i+k][j+7] == 'W') cnt1++;
            }
            for (int k = 1; k < 8; k = k + 2) {
                if(map[i+k][j+0] != 'B') cnt2++;
                if(map[i+k][j+1] != 'W') cnt2++;
                if(map[i+k][j+2] != 'B') cnt2++;
                if(map[i+k][j+3] != 'W') cnt2++;
                if(map[i+k][j+4] != 'B') cnt2++;
                if(map[i+k][j+5] != 'W') cnt2++;
                if(map[i+k][j+6] != 'B') cnt2++;
                if(map[i+k][j+7] != 'W') cnt2++;
            }
            for (int k = 0; k < 8; k = k + 2) {
                if(map[i+k][j+0] == 'B') cnt2++;
                if(map[i+k][j+1] == 'W') cnt2++;
                if(map[i+k][j+2] == 'B') cnt2++;
                if(map[i+k][j+3] == 'W') cnt2++;
                if(map[i+k][j+4] == 'B') cnt2++;
                if(map[i+k][j+5] == 'W') cnt2++;
                if(map[i+k][j+6] == 'B') cnt2++;
                if(map[i+k][j+7] == 'W') cnt2++;
            }
            cnt1 = (cnt1 < cnt2 ? cnt1 : cnt2);
            if(cnt1 < result) result = cnt1;
        }
    }

    for (int i = 0; i < n; i++)
        delete[] map[i];
    delete[] map;
    cout << result;
    return 0;
}
//
// Created by 규북 on 2023/07/23.
//
