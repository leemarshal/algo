#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> name;
    map<int, string> num;
    int n, m;
    cin >> n >> m;
    string s;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        name[s] = i;
        num[i] = s;
    }
    int temp;
    for(int i = 0; i < m; i++) {
        cin >> s;
        if(s[0] <= 57) {
            temp = stoi(s);
            cout << num[temp] << "\n";
        }
        else cout << name[s] << "\n";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/29.
//
