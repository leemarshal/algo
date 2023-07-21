#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, n, result;
    cin >> N;

    int cnt2 = 0, cnt5 = 0;
    n = N;
    while(n > 1) {
        n /= 2;
        cnt2 += n;
    }
    n = N;
    while(n > 1) {
        n /= 5;
        cnt5 += n;
    }

    result = (cnt2 < cnt5) ? cnt2 : cnt5;
    cout << result;

    return 0;
}
//
// Created by 규북 on 2023/07/21.
//
