#include <iostream>
#include <istream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    char s[102];
    stack<char> st;
    int i;
    bool flag = true;
    cin.getline(s, 101);
    while(s[0] != '.') {
        i = 0;
        while(s[i] != '.') {
            if(s[i] == '(') {
                st.push('(');
            }
            else if(s[i] == '[') {
                st.push('[');
            }
            else if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else {
                    flag = false;
                    break;
                }
            }
            else if(s[i] == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else {
                    flag = false;
                    break;
                }
            }
            i++;
        }
        if(!st.empty()) flag = false;
        if(flag) cout << "yes\n";
        else cout << "no\n";
        while(!st.empty()) st.pop();
        cin.getline(s, 101);
        flag = true;
    }
    return 0;
}
//
// Created by 규북 on 2023/08/05.
//
