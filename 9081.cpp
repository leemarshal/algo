#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int index = s.length() - 1;
        while(s[index] <= s[index - 1] && index > 0) index--;
        if(index == 0) {
            cout << s << "\n";
            continue;
        }
        string sub = s.substr(index);
        sort(sub.begin(), sub.end());
        int pos = 0;
        while (s[index - 1] >= sub[pos]) pos++;
        char temp;
        temp = s[index - 1];
        s[index - 1] = sub[pos];
        sub[pos] = temp;
        sort(sub.begin(), sub.end());
        s = s.substr(0, index);
        s = s + sub;
        cout << s << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/15.
//
