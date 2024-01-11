#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k, l;
    cin >> k >> l;
    unordered_map<string, int> student;
    for(int i = 0; i < l; i++) {
        string temp;
        cin >> temp;
        student[temp] = i;
    }
    vector<pair<string, int>> v;
    for(auto it = student.begin(); it != student.end(); it++) v.push_back(*it);
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    for(int i = 0; i < min(k, (int)v.size()); i++) cout << v[i].first << "\n";
    return 0;
}
//
// Created by 규북 on 1/12/24.
//
