#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int cnt = 0;
    vector<int> v;
    v.push_back(0);
    for(size_t i = 0; i < m - 2; i++) {
        char c = s[i];
        if(c == 'O') continue;
        while(s[i + 1] == 'O' && s[i + 2] == 'I') {
            cnt++;
            i += 2;
        }
        v.push_back(cnt);
        cnt = 0;
    }
    cnt = 0;
    for(auto i = v.begin(); i < v.end(); i++) {
        if(*i < n) continue;
        cnt += *i - n + 1;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/08/31.
//
