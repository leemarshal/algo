#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int tCnt = 0; tCnt < t; tCnt++) {
        int n;
        cin >> n;
        if(n == 0) {
            cout << "0\n";
            continue;
        }
        unordered_map<string, int> uMap;
        for(int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            if(uMap.find(type) != uMap.end()) uMap[type]++;
            else uMap[type] = 1;
        }
        int result = 1;
        for(auto& it : uMap) result *= (it.second + 1);
        cout << --result << "\n";
    }
    return 0;
}
//
// Created by 규북 on 1/13/24.
//
