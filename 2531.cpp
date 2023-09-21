#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> v(N);
    int dp[3001] = {};
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int max = -1;
    int cnt = 1;
    for(int i = 0; i < k; i++) {
        if(v[i] == c) continue;
        if(dp[v[i]] == 0) cnt++;
        dp[v[i]]++;
    }
    max = cnt;
    for(int i = 0, j = k; i < N; i++, j++) {
        i %= N;
        j %= N;
        dp[v[i]]--;
        if(v[i] != c && dp[v[i]] == 0) cnt--;
        dp[v[j]]++;
        if(v[j] != c && dp[v[j]] == 1) cnt++;
        if(cnt > max) max = cnt;
    }
    cout << max;
    return 0;
}
//
// Created by 규북 on 2023/09/21.
//
