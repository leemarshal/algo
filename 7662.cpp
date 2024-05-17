#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, K;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> K;
        multiset<int> ms;
        char q;
        int i;
        for(int k = 0; k < K; k++) {
            cin >> q >> i;
            if(q == 'I') ms.insert(i);
            else if(q == 'D') {
                if(ms.empty()) continue;
                auto it = ms.begin();
                if(i == 1) it = --ms.end();
                ms.erase(it);
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *ms.rbegin() << " " << *ms.begin() << "\n";
    }
    return 0;
}
//
// Created by 규북 on 5/18/24.
//
