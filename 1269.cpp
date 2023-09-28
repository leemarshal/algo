#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    set<int> myset;
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        myset.insert(temp);
    }
    int cnt = n + m;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(myset.find(temp) != myset.end()) cnt -= 2;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/09/28.
//
