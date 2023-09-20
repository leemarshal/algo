#include <iostream>
#include <vector>
using namespace std;
int binSearch(const vector<long long>& v, int t) {
    int l = 0;
    int r = v.size() - 1;
    int mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(v[mid] == t) return mid;
        else if(v[mid] > t) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) v[i] += v[i - 1];
    int cnt = 0;
    long long temp;
    if(binSearch(v, m) != -1) cnt++;
    for(int i = 0; i < n; i++) {
        temp = m + v[i];
        if(binSearch(v, temp) != -1) cnt++;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/09/20.
//
