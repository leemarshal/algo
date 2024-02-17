#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    cin >> x;
    vector<pair<int, int>> dp(1000001, {0, 0});
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(q.front().first != x) {
        auto curp = q.front();
        int cur = curp.first;
        q.pop();
        if(cur * 3 <= 1000000 && dp[cur * 3].first == 0) {
            dp[cur * 3] = {cur, curp.second + 1};
            q.push({cur * 3, curp.second + 1});
        }
        if(cur * 2 <= 1000000 && dp[cur * 2].first == 0) {
            dp[cur * 2] = {cur, curp.second + 1};
            q.push({cur * 2, curp.second + 1});
        }
        if(cur + 1 <= 1000000 && dp[cur + 1].first == 0) {
            dp[cur + 1] = {cur, curp.second + 1};
            q.push({cur + 1, curp.second + 1});
        }
    }
    cout << dp[x].second << "\n" << x;
    while(dp[x].first != 0) {
        cout << " " << dp[x].first;
        x = dp[x].first;
    }
    return 0;
}
//
// Created by 규북 on 2/17/24.
//
