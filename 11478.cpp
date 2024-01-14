#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    unordered_map<string, bool> dict;
    for(int i = 0; i < (int)s.length(); i++) {
        int jLen = (int)s.length() - i;
        for(int j = 1; j <= jLen; j++) {
            string sub = s.substr(i, j);
            dict[sub] = true;
        }
    }
    cout << dict.size();
}
//
// Created by 규북 on 1/14/24.
//
