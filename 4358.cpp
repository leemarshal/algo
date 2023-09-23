#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> m;
    string line;
    int cnt = 0;
    while(getline(cin, line)) {
        if(line.empty()) break;
        m[line]++;
        cnt++;
    }
    float r;
    for(const auto& temp : m) {
        cout << temp.first;
        r = (static_cast<float>(temp.second) / cnt) * 100;
        cout << " " << fixed << setprecision(4) << r << "\n";
    }
}
//
// Created by 규북 on 2023/09/23.
//
