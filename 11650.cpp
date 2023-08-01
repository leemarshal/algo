#include <iostream>
#include <utility>
#include  <vector>
#include  <algorithm>

using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << it->first << " " << it->second << " \n";
    }
    return 0;
}
//
// Created by 규북 on 2023/08/01.
//
