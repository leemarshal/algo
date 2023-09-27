#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<string> sset;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sset.insert(s);
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(sset.find(s) != sset.end()) cnt++;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/09/27.
//
