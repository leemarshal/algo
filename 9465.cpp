#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        int n;
        cin >> n;
        vector<vector<int>> dp(2, vector<int>(n, 0));

        for(int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dp[i][j];
            }
        }

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];
        int ti, M;
        for(int j = 2; j < n; j++) {
            for(int i = 0; i < 2; i++) {
                ti = i ? 0 : 1;
                M = dp[ti][j - 1] > dp[ti][j - 2] ? dp[ti][j - 1] : dp[ti][j - 2];
                dp[i][j] += M;
            }
        }

        cout << (dp[0][n - 1] > dp[1][n - 1] ? dp[0][n - 1] : dp[1][n - 1]) << "\n";
    }
}

//
// Created by 규북 on 3/7/24.
//
