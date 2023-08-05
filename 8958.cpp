#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, score = 0, cnt = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(auto it = s.begin(); it != s.end(); it++) {
            if(*it == 'O') cnt++;
            else cnt = 0;
            score += cnt;
        }
        cout << score << "\n";
        cnt = 0;
        score = 0;
    }
}
//
// Created by 규북 on 2023/08/06.
//
