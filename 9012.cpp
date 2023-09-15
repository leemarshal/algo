#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T > 0) {
        string s;
        bool flag = true;
        cin >> s;
        stack<char> stk;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') stk.push(s[i]);
            else if(!stk.empty()) stk.pop();
            else {
                flag = false;
                break;
            }
        }
        if(!stk.empty()) flag = false;
        if(flag) cout << "YES\n";
        else cout << "NO\n";
        T--;
    }
    return 0;
}
//
// Created by 규북 on 2023/09/15.
//
