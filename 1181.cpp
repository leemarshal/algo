#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string& s1, const string& s2) {
    if(s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> v;
    int n;
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto i = v.begin(); i < v.end(); i++)
        cout << *i << "\n";
    return 0;
}
//
// Created by 규북 on 2023/09/01.
//
