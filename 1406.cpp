#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    list<char> text = {'O'};
    char cmd1, cmd2;
    cin >> s;
    cin >> n;
    for(char c : s) {
        text.push_back(c);
    }
    list<char>::iterator cur = --text.end();
    for(int i = 0; i < n; i++) {
        cin >> cmd1;
        if(cmd1 == 'P') {
            cin >> cmd2;
            cur++;
            cur = text.insert(cur, cmd2);
        }
        else if(cmd1 == 'L') {
            if(cur == text.begin()) continue;
            else cur--;
        }
        else if(cmd1 == 'D') {
            if(cur == --text.end()) continue;
            else cur++;
        }
        else {
            if(cur == text.begin()) continue;
            else {
                cur = text.erase(cur);
                cur--;
            }
        }
    }
    cur = ++text.begin();
    while (cur != text.end()) {
        cout << *cur;
        cur++;
    }
    return 0;
}
//
// Created by 규북 on 2023/07/27.
//
