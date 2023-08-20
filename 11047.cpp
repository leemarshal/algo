#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, temp, cnt = 0;
    cin >> n >> k;
    int arr[10];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] > k) continue;
        temp = k / arr[i];
        cnt += temp;
        k = k - temp * arr[i];
        if(k == 0) break;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/08/20.
//
