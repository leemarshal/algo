#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int time[1500001];
    int pay[1500001];
    unsigned int dp[1500001] = {};
    for(int i = 1; i <= n; i++) {
        cin >> time[i] >> pay[i];
    }
    int max = 0;
    for(int i = 1; i <= n; i++) {
        int nxt = i + time[i] - 1;
        if(nxt > n) {
            if(dp[i] > max) max = dp[i];
            continue;
        }
        int temp = pay[i] + max;
        if(temp > dp[nxt]) dp[nxt] = temp;
        if(dp[i] > max) max = dp[i];
    }
    cout << max;
    return 0;
}
//
// Created by 규북 on 2023/09/06.
//
