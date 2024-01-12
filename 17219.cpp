#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> uMap;
    for(int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;
        uMap[site] =  pw;
    }
    for(int i = 0; i < m; i++) {
        string site;
        cin >> site;
        cout << uMap[site] << "\n";
    }
    return 0;
}
//
// Created by 규북 on 1/13/24.
//
