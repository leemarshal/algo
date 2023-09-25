#include <iostream>
#include <string>
using namespace std;
bool isP(string& s, int i) {
    int l = i;
    int r = s.length() - 1;
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if (isP(s, i)) {
            cout << s.length() + i;
            break;
        }
    }
    return 0;
}
//
// Created by 규북 on 2023/09/25.
//
