#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n;
    cin >> T;
    vector<long long> v = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    v.resize(100);
    int p = 5;
    for(int i = 10; i < 100; i++) {
        v[i] = v[i - 1] + v[p];
        p++;
    }

    for(int t = 0; t < T; t++) {
        cin >> n;
        cout << v[n - 1] << "\n";
    }

    return 0;
}
//
// Created by 규북 on 5/24/24.
//
