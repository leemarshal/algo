#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
//
// Created by 규북 on 2023/08/05.
//
