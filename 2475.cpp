#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    a *= a;
    b *= b;
    c *= c;
    d *= d;
    e *= e;
    a = (a + b + c + d + e) % 10;
    cout << a;
}
//
// Created by 규북 on 2023/08/06.
//