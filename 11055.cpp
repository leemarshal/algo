#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sum(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sum.assign(arr.begin(), arr.end());
    int result = arr[0];
    for(int i = 1; i < n; i++) {
        int max = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] >= arr[i]) continue;
            if(sum[j] > max) max = sum[j];
        }
        sum[i] += max;
        if(sum[i] > result) result = sum[i];
    }
    cout << result;
    return 0;
}
//
// Created by 규북 on 2023/09/03.
//
