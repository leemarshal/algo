#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, temp, x, cnt = 0, begin, end;
    cin >> n;
    bool arr[1000000] = {false};
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[temp - 1] = true;
    }
    cin >> x;
    if (x % 2 == 0)
        end = (x / 2) - 1;
    else
        end = (x / 2);
    if (x > 1000000)
        begin = x - 1000000 - 1;
    else
        begin = 0;

    for (int i = begin; i < end; i++) {
        if (arr[i] && arr[x - i - 2])
            cnt++;
    }

    cout << cnt;

    return 0;
}
//
// Created by 규북 on 2023/07/26.
//
