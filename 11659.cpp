#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int arr[100000];
    cin >> n >> m;
    int t, u;
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> t;
        arr[i] = arr[i - 1] + t;
    }
    for(int i = 0; i < m; i++) {
        cin >> t >> u;
        t--;
        u--;
        if(t == 0) {
            cout << arr[u] << "\n";
            continue;
        }
        cout << arr[u] - arr[t - 1] << "\n";
    }
    return 0;
}
/*
 * idea : dp based
 * start to k sum : O(n)
 * need to find (start to j) - (start to i-1)
 */
//
// Created by 규북 on 2023/08/22.
//
