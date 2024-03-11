#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int arr[1001];
    int dp[2][1001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && dp[0][i] < dp[0][j] + 1) {
                dp[0][i] = dp[0][j] + 1;
            }
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(arr[i] > arr[j] && dp[1][i] < dp[1][j] + 1) {
                dp[1][i] = dp[1][j] + 1;
            }
        }
    }
    int result = -1;
    for(int i = 0; i < n; i++) {
        result = dp[0][i] + dp[1][i] - 1 > result ? dp[0][i] + dp[1][i] - 1 : result;
    }
    cout << result;
}

//
// Created by 규북 on 3/11/24.
//
