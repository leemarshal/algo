#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, bool> m;
    for(int i = 0; i < n; i++) {
        string name, s;
        cin >> name >> s;
        if(s[0] == 'e') m[name] = true;
        else m[name] = false;
    }
    for(auto it = m.rbegin(); it != m.rend(); it++) {
        if(it->second) cout << it->first << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/25.
//
