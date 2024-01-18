#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s;
    cin >> n >> s;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = arr[0], i = 0, j = 1, cnt = 1, ans = 1000000000;
    bool flag = false;
    while(true) {
        if(sum >= s) {
            if(cnt < ans) {
                ans = cnt;
                flag = true;
                if(ans == 1) break;
            }
            if(i == n - 1) break;
            sum -= arr[i++];
            cnt--;
        }
        else if(sum < s) {
            if(j == n) break;
            sum += arr[j++];
            cnt++;
        }
    }
    if(flag) cout << ans;
    else cout << "0";
    delete []arr;
    return 0;
}
//
// Created by 규북 on 1/18/24.
//
