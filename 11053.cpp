#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[1000];
    int dp[1000] = {};
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = 1;
    int max = 1;
    int cnt;
    for(int i = 1; i < n; i++) {
        cnt = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] >= arr[i]) continue;
            if(dp[j] > cnt) cnt = dp[j];
        }
        dp[i] = cnt + 1;
        if(dp[i] > max) max = dp[i];
    }
    cout << max;
    return 0;
}
//
// Created by 규북 on 2023/09/04.
//
