#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool flag = true;
    cin >> n;
    short arr[26];
    for (int i=0; i<26; i++)
        arr[i] = 0;
    string s1, s2;
    for (int i=0; i<n; i++) {
        cin >> s1 >> s2;
        if(s1.size() != s2.size()) {
            cout << "Impossible\n";
            continue;
        }
        for (int j=0; j<s1.size(); j++) {
            arr[s1[j]-97]++;
            arr[s2[j]-97]--;
        }
        for (int j=0; j<26; j++) {
            if(arr[j] != 0) {
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
        for (int j=0; j<26; j++)
            arr[j] = 0;
        flag = true;
    }
    return 0;
}
//
// Created by 규북 on 2023/07/24.
//
