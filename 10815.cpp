#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binSearch(const vector<int>& v, int t) {
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
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> m;
    int temp;
    sort(v.begin(), v.end());
    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(binSearch(v, temp) == -1) cout << "0 ";
        else cout << "1 ";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/17.
//
