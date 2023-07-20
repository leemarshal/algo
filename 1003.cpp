#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 41> a, b;

    a[0] = 1, a[1] = 0;
    b[0] = 0, b[1] = 1;
    int T, lastIndex=1;

    cin >> T;
    vector<int> test(T);
    for(int i=0; i<T; i++) {
        cin >> test[i];
        if(test[i] <= lastIndex) {
            cout << a[test[i]] << " " << b[test[i]] << "\n";
            continue;
        }
        for(int j=lastIndex+1; j<=test[i]; j++) {
            a[j] = a[j-1] + a[j-2];
            b[j] = b[j-1] + b[j-2];
        }
        cout << a[test[i]] << " " << b[test[i]] << "\n";
        lastIndex = test[i];
    }
}
//
// Created by 규북 on 2023/07/17.
//
