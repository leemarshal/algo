#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int cnt = 0;
    cin >> s;
    s = s + "..";
    for(int i = 0; i < s.length() - 2; i++) {
        if(s[i] == 'c') {
            if(s[i + 1] == '=' || s[i + 1] == '-') {
                cnt++;
                i++;
            }
            else cnt++;
        }
        else if(s[i] == 'd') {
            if(s[i + 1] == 'z' && s[i + 2] == '=') {
                cnt++;
                i += 2;
            }
            else if(s[i + 1] == '-') {
                cnt++;
                i++;
            }
            else cnt++;
        }
        else if(s[i + 1] == 'j') {
            if(s[i] == 'l' || s[i] == 'n') {
                cnt++;
                i++;
            }
            else cnt++;
        }
        else if(s[i + 1] == '=') {
            if(s[i] == 's' || s[i] == 'z') {
                cnt++;
                i++;
            }
            else cnt++;
        }
        else cnt++;
    }
    cout << cnt;
    return 0;
}
//
// Created by 규북 on 2023/09/14.
//
