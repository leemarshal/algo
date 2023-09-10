#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> card;
    int temp, n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        auto result = card.insert({temp, 1});
        if(!result.second) result.first->second++;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        auto it = card.find(temp);
        if(it != card.end()) cout << it->second << " ";
        else cout << "0 ";
    }
    return 0;
}
//
// Created by 규북 on 2023/09/10.
//
