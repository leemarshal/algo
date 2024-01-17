#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(const vector<int>& v, int n) {
    int l = 0;
    int r = v.size() - 1;
    int mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(v[mid] == n) return mid;
        else if(v[mid] > n) r = mid - 1;
        else l = mid + 1;
    }
    if(v[mid] > n) return mid;
    else if(mid < v.size() - 2) return mid + 1;
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 2000000001;
    for(auto& it : v) {
        int index = binSearch(v, it + m);
        if(index == -1) continue;
        if(v[index] - it < result) result = v[index] - it;
    }
    cout << result;
    return 0;
}
//
// Created by 규북 on 1/17/24.
//
